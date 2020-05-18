
#include <stdlib.h>

#include "tree.h"

int max(int a, int b) {return a > b ? a : b;}

int TreeHeight(Tree t) {
    if (t == NULL) return -1;

    int left = TreeHeight(t->left) + 1;
    int right = TreeHeight(t->right) + 1;

    return max(left, right);
}

// int TreeHeight(Tree t) {
//     return -1;
// }
