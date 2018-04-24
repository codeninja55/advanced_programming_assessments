// CSCI251 example: Using STL map insert(), iterator and find() 

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

int main ()
{
	map<char,vector<int> > mymap;  // maps each char to a vector of ints
	map<char,vector<int> >::iterator itr; // iterator for map
	
	// put some chars and ints into the map:
	for (int i=0;i<100;i++){ //insert 100 items
		char ch = 'a' + rand()%7; // random alpha: a,b,c,d,e,f or g 
		
		itr = mymap.find(ch);
		if(itr != mymap.end())// then already in map... 
			(*itr).second.push_back(i); // so add index to vector
		else{ // not in map, so insert ch and index into map...
			vector<int> vect(1,i); // construct vector with one element
			mymap.insert(itr, pair<char, vector<int> >(ch,vect)); // typecast ch & vect into a pair and insert it
		}
	}
	// print out the map:
	cout << "Ch  Cnt  Indexes\n";
	for (itr = mymap.begin();  itr != mymap.end();  ++itr){
		char ch = (*itr).first;
		vector<int> vect = (*itr).second;
		int cnt = vect.size();
		cout << ch << setw(5) << cnt << "   ";
		for (int i=0;i<cnt;i++)
			cout <<  vect[i] << ' ';
		cout << endl;
	}
	cout << endl;
	// print chars in order of occurrence...
	multimap<int,char> m; // new map with int as key (multimap because key could occur more than once)
	for (itr = mymap.begin();  itr != mymap.end(); ++itr){ // iterate map again
		char ch = (*itr).first;
		int cnt = (*itr).second.size();
		m.insert(pair<int,char>(cnt,ch)); // insert with count as the key
	}

	// print out the new map:
	multimap<int,char>::iterator itx; // iterator for new map
	cout << "Cnt  Ch\n";
	for (itx = m.begin(); itx != m.end(); ++itx){
		char ch = (*itx).second;
		int cnt = (*itx).first;
		cout << setw(3) << cnt << "   " << ch << endl;
	}
	cout << endl;

	return 0;
}

