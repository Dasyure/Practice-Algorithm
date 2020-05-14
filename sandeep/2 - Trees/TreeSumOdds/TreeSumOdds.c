
#include <stdlib.h>

#include "tree.h"

int TreeSumOdds(Tree t) {
	if (t == NULL) return 0;

	int sum = 0;
	if (t->value % 2 != 0) {
		sum += t->value;
	}

	int leftSum = TreeSumOdds(t->left);
	int rightSum = TreeSumOdds(t->right);
	sum += leftSum + rightSum;
	return sum;
}


// int TreeSumOdds(Tree t) {
// 	return 0;
// }
