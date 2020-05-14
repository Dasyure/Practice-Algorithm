
#include "list.h"

bool listIsOrdered(List l) {
	// TODO
	int did = 0;
	Node curr = l->head;
	if (curr == NULL) {
		return true;
	}
	while (curr->next != NULL) {
		if (curr->value <= curr->next->value) {
			if (did == 2) {
				return false;
			}
			did = 1;
		}
		else if (curr->value >= curr->next->value) {
			if (did == 1) {
				return false;
			}
			did = 2;
		}
		curr = curr->next;
	}

	return true;
}

