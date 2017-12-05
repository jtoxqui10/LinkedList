#include <iostream>
#include <cassert>
#include "list.h"

using namespace std;

void test() {
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
void test2() {
	List x;
	x.push_back(3);
	x.push_back(9);
	assert(x.empty() == false);
	assert(x.size() == 2);
	x.push_front(5);
	Iterator it = x.begin();
	++it;
	assert(*it == 3);
	x.erase(it);
	assert(x.size() == 2);
	it = x.begin();
	assert(*it == 5);
	it = x.begin();
	x.insert(it, 7);
	it = x.begin();
	assert(*it == 7);
	++it;
	assert(*it == 5);
	++it;
	assert(*it == 9);	
}
void test3() {
	List x;
	x.push_front(4);
	x.push_back(8);
	x.push_back(2);
	assert(x.size() == 3);
	x.pop_front();
	assert(x.size() == 2);
	x.pop_back();
	assert(x.size() == 1);
	x.pop_back();
	assert(x.size() == 0);
	Iterator it = x.begin();
	x.erase(it);
	assert(x.size() == 0);
	x.push_front(20);
	x.push_back(21);
	x.push_back(22);
	assert(x.size() == 3);
	it = x.begin();
	x.insert(it, 19);
	assert(x.size() == 4);
	++it;
	assert(*it == 21);
	x.erase(it);
	assert(x.size() == 3);
	it = x.begin();
	assert(*it == 19);
	++it;
	assert(*it == 20);
	++it;
	assert(*it == 22);
	x.erase(it);
	assert(x.size() == 2);
	x.pop_front();
	assert(x.size() == 1);
	it = x.begin();
	assert(*it == 20);
	x.pop_back();
	assert(x.size() == 0);
}
void test4() {
        List x;
        x.push_front(4);
        x.erase(x.begin());
}
int main() {
	test();
	test2();
	test3();
	test4();
	cout << "All tests passed.";
}


