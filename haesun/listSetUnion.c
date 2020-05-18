#include<stdbool.h>
#include "list.h"
#include "string.h"
 
bool isPresent (Node head, int value);

List listSetUnion(List s1, List s2) {
	// TODO
	if (s1->head == NULL && s2->head == NULL) {
		return newList();
	}
	else if (s1->head == NULL && s2->head != NULL) {
		List ans = newList();
		Node currS2 = s2->head;
		ans->head = newNode(currS2->value);
		Node curr = ans->head;
		currS2 = currS2->next;
		while (currS2 != NULL) {
			curr->next = newNode(currS2->value);
			curr = curr->next;
			currS2 = currS2->next;
		}
		return ans;
	}
	else if (s1->head != NULL && s2->head == NULL) {
		List ans = newList();
		Node currS1 = s1->head;
		ans->head = newNode(currS1->value);
		Node curr = ans->head;
		currS1 = currS1->next;
		while (currS1 != NULL) {
			curr->next = newNode(currS1->value);
			curr = curr->next;
			currS1 = currS1->next;
		}
		return ans;
	}
	List ans = newList();
	Node currS2 = s2->head;
	Node currS1 = s1->head;
	ans->head = newNode(currS1->value);
	Node curr = ans->head;
	currS1 = currS1->next;
	while (currS1 != NULL) {
		curr->next = newNode(currS1->value);
		curr = curr->next;
		currS1 = currS1->next;
	}
	Node currAns = ans->head;
	while (currAns != NULL) {
		while (currS2 != NULL) {
			if (!isPresent(s1->head, currS2->value)) {
				curr->next = newNode(currS2->value);
				curr = curr->next;
			}
			currS2 = currS2->next;
		}
		currAns = currAns->next;
	}

	return ans;
}


bool isPresent (Node head, int value) {
	Node t = head;
	while (t != NULL) {
		if (t->value == value) {
			return 1;
		}
		t = t->next;
	}
	return 0;
}
