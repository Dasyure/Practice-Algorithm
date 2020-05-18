
#include "tree.h"

Tree TreeCopy(Tree t, int depth) {
	if (t == NULL || depth < 0) {
		return NULL;
	} else if (depth == 0) {
		Tree new = malloc(sizeof(*new));
		new->value = t->value;
		new->left = NULL;
		new->right = NULL;
		return new;
	} else {
		Tree new = malloc(sizeof(*new));
		new->value = t->value;
		new->left = TreeCopy(t->left, depth - 1);
		new->right = TreeCopy(t->right, depth - 1);
		return new;
	}
}

// Tree TreeCopy(Tree t, int depth) {
// 	// TODO
// 	return NULL;
// }
