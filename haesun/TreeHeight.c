
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t) {
    if (t == NULL) {
        return -1;
    }
    int depthL = TreeHeight(t->left);
    int depthR = TreeHeight(t->right);
    if (depthL > depthR) {
        return (depthL + 1);
    }
    else {
        return (depthR + 1);
    }
}

