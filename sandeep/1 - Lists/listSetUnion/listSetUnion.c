
#include "list.h"

List appendNode (List l, Node new) {
	if (l->head == NULL) l->head = new;
	else {
		Node curr = l->head;
		while (curr->next != NULL) {
			// If node already exists, ignore
			if (new->value == curr->value) {free(new); return l;}
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

List addLists (List l, List new) {
	if (new == NULL) return l; 
	Node curr = new->head;
	while (curr != NULL) {
		Node new = newNode(curr->value);
		l = appendNode(l, new);
		curr = curr->next;
	}
	return l;
}

List listSetUnion(List s1, List s2) {
	List s  = newList();
	s = addLists(s, s1);
	s = addLists(s, s2);
	return s;
}


// List listSetUnion(List s1, List s2) {
// 	// TODO
// 	return newList();
// }