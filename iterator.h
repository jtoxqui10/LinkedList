#pragma once

#include "link.h"

class Iterator {
public:
	void operator++();
	int & operator*() const;
	bool operator==(const Iterator & rhs); //right hand side
	

private:
	Iterator(Link * link) : link(link) {}
	
	Link * link;

	friend class List;
};
