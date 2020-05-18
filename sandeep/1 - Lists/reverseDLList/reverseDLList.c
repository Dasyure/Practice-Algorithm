
#include "list.h"

void reverseDLList(List l) {
	if (l == NULL) return;
	if (l->first == NULL) return;

	Node curr = l->first;
	l->last = curr;
	Node prev = NULL;
	Node nxt = NULL;
	while (curr != NULL) {
		// Store next
		nxt = curr->next;
		// Reverse pointer
		curr->next = prev;
		curr->prev = nxt;
		// Update pointers
		prev = curr;
		curr = nxt;
	}
	l->first = prev;
}


// void reverseDLList(List l) {
// 	// TODO
// }

