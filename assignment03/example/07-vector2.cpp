// CSCI251 example: STL vector

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iterator>
using namespace std;

class personname {   
  public:
	personname();
	personname(const char name[]);
	const char* getname() const;
  private:
	char pname[128];
};

personname::personname()
{  
    strcpy(pname,"");
}

personname::personname(const char* name)
{
    strcpy(pname, name);
}

const char* personname::getname() const
{
    return pname;
}

bool operator<(const personname & lhs, const personname& rhs)
{
    return (strcmp(lhs.getname(), rhs.getname()) < 0);
}

bool operator==(const personname& lhs, const personname& rhs)
{
    cout<<"calling operator== in the object"<<endl;
    return (strcmp(lhs.getname(), rhs.getname()) ==0);
}

int main()
{
    vector<personname> v1;
    vector<personname> v2;

    v1.push_back(personname("Peter"));
    v2.push_back(personname("Peter"));
    if (v1==v2) 
	    cout<<"They are same"<<endl;
    else
	    cout<<"They are different"<<endl;
	    
    return 0;
}


