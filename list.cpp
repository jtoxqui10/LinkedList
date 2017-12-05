#include "list.h"
#include <cassert>

List::~List () {
	Link *node = head;
	while (node != 0) {
		Link *pt = node->next; 
		delete node;
		node = pt;
	} 
}

bool List::empty() const {
	return head == 0;
}

int List::size() {
	int count = 0;
	Link * temp = head;
	while(temp != 0) {
		++count;
		temp = temp->next;
	}
	return count;
}

void List::push_front(int x) {
	Link * temp = new Link(0, x);

	if(head == 0) {
		head = temp;
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
	if (it.link == head) { 
		Link *pt = head->next;
		delete head;
		head = pt; 
//		return; 
	}
	else {
		Link *prev = head;
		while (prev->next != it.link) {
			prev = prev->next;
		}
		Link *o = prev->next;
		prev->next = prev->next->next;
		delete o;
	}
}

Iterator List::begin() {
	return Iterator(head);
}

Iterator List::end() {
	return Iterator(0);
}
