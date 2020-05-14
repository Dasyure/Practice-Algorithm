
#include <stdlib.h>

#include "BSTree.h"
#define NOT_FOUND -1

int max(int a, int b) {return a > b ? a : b;}

int BSTreeNodeDepth(BSTree t, int key) {
	if (t == NULL) return NOT_FOUND;
	if (t->value == key) {
		return 0;
	}

	int leftDepth = BSTreeNodeDepth(t->left, key);
	int rightDepth = BSTreeNodeDepth(t->right, key);

	if (leftDepth == NOT_FOUND && rightDepth == NOT_FOUND) {
		return NOT_FOUND;
	}
	return max(leftDepth + 1, rightDepth + 1);
}

// int BSTreeNodeDepth(BSTree t, int key) {
// 	return 0;
// }
