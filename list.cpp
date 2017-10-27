#include "list.h"
#include <cassert>

bool List::empty() const {
	return head == 0;
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

void List::push_front(int x) {
	Link * temp = new Link(0, x);

	if(head == 0) {
		head = temp;
		tail = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
}

void List::pop_front() {
	Link * temp = new Link(0, 0);
	temp = head->next;
	delete head;
	head = temp;

}

void List::push_back(int x) {
	if (head == 0) {
		head = new Link(0, x);
	} else {
		Link * link = head;
		while (link->next != 0) {
			link = link->next;
		}
		link->next = new Link(0, x);
	}
}

void List::pop_back() {
	assert(head != 0);
	
	if(head->next == 0) {
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

Iterator List::insert(Iterator it, int n) {
	assert(it.link != 0);
	if(it.link == head) {
		push_front(n);
	}
	else {
	Link * prev = head;
	while(prev->next != it.link) {
		prev = prev->next;
	}
 	prev->next = new Link(0, n);
	}
}

Iterator List::erase(Iterator it) {
	assert(head != 0);
	Link * prev = head;
	while(prev->next != it.link) {
		prev = prev->next;
	}
	Link * newnext = prev->next->next;
	delete prev->next;
	prev->next = newnext;
}


Iterator List::begin() {
	return Iterator(head);
}

Iterator List::end() {
	return Iterator(0);
}
