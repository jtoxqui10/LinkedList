#pragma once

class Link {
public:
	Link() {}
	Link(Link * y, int x ) {
		data = x;
		next = y;
	}
private:
	int data;
	Link * next;

	friend class List;
	friend class Iterator;

};
