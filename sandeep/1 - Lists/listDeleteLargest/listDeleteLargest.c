
#include "list.h"

int findLargest(List l) {
	Node curr = l->head;
	int largest = curr->value;
	while (curr != NULL) {
		if (curr->value > largest) largest = curr->value; 
		curr = curr->next;
	}
	return largest;
}

void deleteNode(List l, Node prev, Node curr) {
	Node next = curr->next;
	if (prev == NULL) {
		l->head = next;
	} else {
		prev->next = next;
	}
	free(curr);
}

// Assume given list is not empty
int listDeleteLargest(List l) {
	Node curr = l->head;
	Node prev = NULL;
	int largest = findLargest(l);
	while (curr != NULL) {
		if (curr->value == largest)  {
			deleteNode(l, prev, curr);
			break;
		}
		if (curr == l->head) {prev = curr;}
		else {prev = prev->next;}
		curr = curr->next;
	}
	// printf("%d\n", l->head->value);
	return largest;
}

// int listDeleteLargest(List l) {
// 	return -1;
// }
