#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person();
    Person(string newName, int newId);
    int getID();
    string getName();
    void setID(int setId);
    void setName(string name);
    string printPerson();
    
    //operator overloads to add comparison functionality to it and all inheriting classes (Student + faculty) so that they can be compared in the BST for traversal/insertion/etc
    bool operator==(const Person& right);
    bool operator<(const Person& right);
    bool operator>(const Person& right);
    bool operator<=(const Person& right);
    bool operator>=(const Person& right);
private:
    string name;
    int id;
    
    
};
#endif

