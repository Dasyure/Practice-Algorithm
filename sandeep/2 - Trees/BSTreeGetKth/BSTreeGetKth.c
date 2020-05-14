
#include <stdlib.h>

#include "BSTree.h"
#define NOT_FOUND -42

int max(int a, int b) {return a > b ? a : b;}

int recBSTreeGetkth (BSTree t, int k, int *nodes) {
	if (t == NULL) return NOT_FOUND;

	int left = recBSTreeGetkth(t->left, k, nodes);

	if (left == NOT_FOUND) {
		if (k == *nodes) {
			return t->value;
		}
		(*nodes)++;
		int right = recBSTreeGetkth(t->right, k, nodes);
		return max(left, right);
	}
	return left;
}


int BSTreeGetKth(BSTree t, int k) {
	int nodes = 0;
	return recBSTreeGetkth(t, k, &nodes);
}

// int BSTreeGetKth(BSTree t, int k) {
// 	// TODO
// 	return -42;
// }
