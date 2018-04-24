// CSCI251 example: Using STL set::insert(), set::iterator and set::find() fns
#include <iostream>
#include <set>
using namespace std;

int main ()
{
	std::set<int> myset;
	std::set<int>::iterator it;
	
	// set some initial values:
	for (int i=1; i<=5; ++i) 
		myset.insert(i*10);    // set: 10 20 30 40 50
	
	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
	std::cout << *it << ' ';
	std::cout << "\n\n";
	
	it = myset.find(20);
	if(it != myset.end()) cout << "found 20 in myset\n";
	else cout << "did not find 20 in myset\n'n";

	it = myset.find(100);
	if(it != myset.end()) cout << "found 100 in myset\n";
	else cout << "did not find 100 in myset\n\n";
	
	
	return 0;
}

