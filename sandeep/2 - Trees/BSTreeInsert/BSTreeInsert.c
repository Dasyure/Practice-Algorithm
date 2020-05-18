
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree newBSTNode(int value) {
	BSTree t = malloc(sizeof(*t));
	if (t == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	t->value = value;
	t->left = NULL;
	t->right = NULL;
	return t;
}

BSTree BSTreeInsert(BSTree t, int val) {
	if (t == NULL) return newBSTNode(val);
	// Go left
	if (val <= t->value) {
		t->left = BSTreeInsert(t->left, val);
	// Go right
	} else if (val > t->value) {
		t->right = BSTreeInsert(t->right, val);
	}
	return t;
}

// BSTree BSTreeInsert(BSTree t, int val) {
// 	// TODO
// 	return NULL;
// }