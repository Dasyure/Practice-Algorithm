
#include "list.h"

int numDupesInOrderedList(List l) {
	if (l == NULL) return true;
	if (l->head == NULL) return true;

	int sum = 0;
	Node curr = l->head;
	Node nxt = curr->next;
	if (nxt == NULL) return sum;
	while (nxt != NULL) {
		if (curr->value == nxt->value) sum++;
		// Update pointers
		curr = curr->next;
		nxt = nxt->next;
	}
	return sum;
}

// int numDupesInOrderedList(List l) {
// 	// TODO
// 	return -1;
// }
