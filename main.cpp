#include <iostream>
#include <cassert>
#include "list.h"

using namespace std;

void push_backTest() {
	List x;
	assert(x.empty() == true);
	assert(x.size() == 0);

	Iterator it = x.begin();
	Iterator end = x.end();
	assert(it == end);

	x.push_back(3);
	assert(x.empty() == false);
	assert(x.size() == 1);
	it = x.begin();
	assert(*it == 3);
	*it = 4;
	assert(*it == 4);
}

int main() {

	cout << "All tests passed.";
}
