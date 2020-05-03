
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"
static BSTree newBSTNode(int value) {
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
	if (t == NULL) {
		return newBSTNode(val);
	}
	if (t->value == val) {
		return t;
	}
	if (t->value < val) {
		t->right = BSTreeInsert(t->right, val);
		return t;
	}
	t->left = BSTreeInsert(t->left, val);
	return t;
}

