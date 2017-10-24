#include "list.h"
#include <cassert>

bool List::empty() const {
	return head == 0;
}

void List::push_front(int x) {
	Link * temp = new Link(0, x);

	if(head == 0) {
		head = temp;
		tail = temp;
	}
	else {
		head->next = temp;
		head = temp;
	}
}

void List::push_back(int x) {
	Link * temp = new Link(0, x);
	
	if(head == 0) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}
int List::size() {
	int count = 0;
	Link * temp = head;
	while(temp != 0) {
		++count;
		temp = temp->next; //how you move to next link
	}
	return count;
}

void List::pop_back() {
	assert(head != 0);
	
	if(head->next == 0) {
		//special case
		delete head;
		head = 0;
		return;
	}
	
	Link * temp = head;

	while(temp->next->next != 0) {
		temp = temp->next;
	}
	
	delete temp->next;
	temp->next = 0;
}

Iterator List::begin() {
	return Iterator(head);
}

Iterator List::end() {
	return Iterator(0);
}
