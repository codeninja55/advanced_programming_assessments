// CSCI251 example: STL list

#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

int main()
{
    // create empty vector for strings
    list<string> sentence;


    // append some elements
    sentence.push_back("Hello,");
    sentence.push_back("how");
    sentence.push_back("are");
    sentence.push_back("you");
    sentence.push_back("?");
    string x = "abcd";
    sentence.push_back(x);

    cout<<"sentence.back() "<<sentence.back()<<endl;

    // print elements separated with spaces
    copy (sentence.begin(), sentence.end(),
          ostream_iterator<string>(cout," "));
    cout << endl;

    // print ``technical data''
    cout << "  max_size(): " << sentence.max_size() << endl;
    cout << "  size():     " << sentence.size()     << endl;

    return 0;
}


