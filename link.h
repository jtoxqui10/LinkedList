#pragma once

class Link {
public:
	Link() {}
	Link(Link * l, int x ) {
		data = x;
		next = l;
	}

	int data;
	Link * next;

};
