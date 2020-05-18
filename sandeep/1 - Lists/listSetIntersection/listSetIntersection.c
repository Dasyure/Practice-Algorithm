
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

List listSetIntersection(List s1, List s2) {
	if (s1 == NULL || s2 == NULL) return NULL;
	if (s1->head == NULL || s2->head == NULL) return NULL;

	List s  = newList();
	Node curr = s1->head;
	while (curr != NULL) {
		if (isInsideList(s2, curr->value)) {
			appendNode(s, newNode(curr->value));
		}
		curr = curr->next;
	}
	return s;
}

// List listSetIntersection(List s1, List s2) {
// 	// TODO
// 	return newList();
// }

