
#include "list.h"

void listReverse(List l) {
	if (l == NULL) return;
	if (l->head == NULL) return;

	Node curr = l->head;
	Node prev = NULL;
	Node nxt = NULL;
	while (curr != NULL) {
		// Store next
		nxt = curr->next;
		// Reverse pointer
		curr->next = prev;
		// Update pointers
		prev = curr;
		curr = nxt;
	}
	l->head = prev;
}


// void listReverse(List l) {
// 	// TODO
// }
