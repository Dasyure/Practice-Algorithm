
#include <stdlib.h>
#include <assert.h>
#include "BSTree.h"
// BSTree rotateRight(BSTree n1);
// BSTree rotateLeft(BSTree n2);
int TreeNumNodes(BSTree t);
int BSTreeGetKth(BSTree t, int k) {
    int kth = -1;
    if (t != NULL) {
        assert(0 <= k && k < TreeNumNodes(t));
        int m = TreeNumNodes(t->left);
        // index < number of nodes, look at left subtree
        if (k == m) {
            kth = t->value;
        }
        else if (k < m) { 
            kth = BSTreeGetKth(t->left, k);
        } 
        else if (k > m) {
            kth = BSTreeGetKth(t->right, k-m-1);
        }
	// // if m == t->value, then it's the node itself.
    }
	return kth;
}
// count #nodes in Tree
int TreeNumNodes(BSTree t) {
	if (t == NULL) {
    	return 0;
    }
    return 1 + TreeNumNodes(t->left) + TreeNumNodes(t->right);
}
