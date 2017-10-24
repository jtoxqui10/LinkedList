#pragma once

#include "iterator.h"

class List {
public:
	List() {
		head = 0;
		tail = 0; 
	} 
	~List() {} //IMPLEMENT LATER
	bool empty() const;
	int size();
	void push_front(int x);
	void pop_front();
	void push_back(int x);
	void pop_back();
	Iterator insert(Iterator it, int n);
	Iterator erase(Iterator it);
	Iterator begin();
	Iterator end();     

private:
	Link * head;
	Link * tail;
};
