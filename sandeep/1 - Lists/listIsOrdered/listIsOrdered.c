
#include "list.h"

bool listIsOrdered(List l) {
	if (l == NULL) return true;
	if (l->head == NULL) return true;

	Node curr = l->head;
	Node nxt = curr->next;
	if (nxt == NULL) return true;
	bool isAscending = curr->value < nxt->value ? true : false;

	while (nxt != NULL) {
		int p = curr->value <= nxt->value;
		int q = isAscending;
		if (!((!p || q) && (!q || p))) return false;

		// Update pointers
		curr = curr->next;
		nxt = nxt->next;
	}
	return true;
}

/**
 * Equivalent of:       if (!((!p || q) && (!q || p))) return false;
 * 
 * is:
 * 
 * 		if (q) {
			if (!p) return false;
		} else if (!q) {
			if (p) return false;
		} 
*/

// bool listIsOrdered(List l) {
// 	// TODO
// 	return false;
// }
