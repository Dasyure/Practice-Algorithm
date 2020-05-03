#include "tree.h"
Tree TreeCopy(Tree t, int depth) {
	if (t == NULL || depth < 0) {
	    return NULL;
    }  
	else {
	    Tree copied_tree = malloc(sizeof(struct node));
        copied_tree->value = t->value;
        copied_tree->left = TreeCopy(t->left, depth - 1);
        copied_tree->right = TreeCopy(t->right, depth - 1);
        return copied_tree;
    }
}

