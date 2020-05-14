
#include <stdlib.h>

#include "tree.h"
#define TRUE 1
#define FALSE !TRUE

int numNodes (Tree t) {
	if (t == NULL) return 0;
	return numNodes(t->left) + numNodes(t->right) + 1;
}

bool TreeIsPerfectlyBalanced(Tree t) {
	if (t == NULL) return TRUE;
	return (abs(numNodes(t->left) - numNodes(t->right)) <= 1 
			&& TreeIsPerfectlyBalanced(t->left)
			&& TreeIsPerfectlyBalanced(t->right));
}

// bool TreeIsPerfectlyBalanced(Tree t) {
// 	// TODO
// 	return false;
// }
