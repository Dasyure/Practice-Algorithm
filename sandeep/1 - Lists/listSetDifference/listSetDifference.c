
#include "list.h"

List appendNode (List l, Node new) {
	if (l->head == NULL) l->head = new;
	else {
		Node curr = l->head;
		while (curr->next != NULL) {
			// Put into list in order
			if (new->value < curr->next->value) {
				new->next = curr->next;
				curr->next = new;
				break;
			}
			curr = curr->next;
		}
		curr->next = new;
	}
	return l;
}

bool isInsideList(List l, int query) {
	if (l == NULL) return false;
	if (l->head == NULL) return false; 
	Node curr = l->head;
	while (curr != NULL) {
		if (curr->value == query) return true;
		curr = curr->next;
	}
	return false;
}

List listSetDifference(List l1, List l2) {
	if (l1 == NULL || l2 == NULL) return NULL;
	if (l1->head == NULL || l2->head == NULL) return NULL;

	List s  = newList();
	Node curr = l1->head;
	while (curr != NULL) {
		if (!isInsideList(l2, curr->value)) {
			appendNode(s, newNode(curr->value));
		}
		curr = curr->next;
	}
	return s;
}

// List listSetDifference(List l1, List l2) {
// 	// TODO
// 	return NULL;
// }

