
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
	/*void push_front(int x);*/
	void push_back(int x);
	void pop_back();
	Iterator begin();
	Iterator end();     //null pointer

private:
	Link * head;
	Link * tail;
};
