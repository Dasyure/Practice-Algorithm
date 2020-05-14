
#include "list.h"

bool listIsPalindromic(List l) {
	if (l == NULL) return true;
	if (l->first == NULL) return true;

	Node front = l->first;
	Node back = l->last;

	while (front != l->last || back != l->first) {
		if (front->value != back->value) {
			return false;
		}
		front = front->next;
		back = back->prev;
	}
	return true;
}

// bool listIsPalindromic(List l) {
// 	// TODO
// 	return false;
// }

