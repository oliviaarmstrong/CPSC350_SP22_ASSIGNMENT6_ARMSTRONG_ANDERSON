#ifndef Faculty_hpp
#define Faculty_hpp

#include <string>
#include "Person.hpp"
#include "GenList.hpp"
using namespace std;

class Faculty: public Person{
private:
    
    string level; //string - prof level
    string department; // string - department
    GenList<int>* advisees; //list of integers corresponding to which students they advise
    
public:
    
    Faculty();
    Faculty(int id, string n, string l, string d, GenList<int>* list);
    ~Faculty();
    
    //accessors
    string getLevel();
    string getDepartment();
    GenList<int>* getAdviseeList();
    
    //mutators
    void setID(int id);
    void setName(string n);
    void setLevel(string l);
    void setDepartment(string d);
    void setAdviseeList(GenList<int>* list);
    
    
    ostream& operator<<(ostream &out);
    string printPerson();
};


#endif

