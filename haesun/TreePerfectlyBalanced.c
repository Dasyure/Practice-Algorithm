// z5253655 Haesun Shim
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
int TreeNumNodes(Tree t);
bool TreeIsPerfectlyBalanced(Tree t) {
	// TODO
	if (t == NULL) {
	    return true;
    }
	if (TreeNumNodes(t->left) - TreeNumNodes(t->right) < 2 && 
		TreeNumNodes(t->right) - TreeNumNodes(t->left) < 2) {
	    
		return TreeIsPerfectlyBalanced(t->left) && TreeIsPerfectlyBalanced(t->right);
	}
	return false;
}
int TreeNumNodes(Tree t) {
	if (t == NULL) {
    	return 0;
    }
    return 1 + TreeNumNodes(t->left) + TreeNumNodes(t->right);
}