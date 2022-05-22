#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Person.hpp"
using namespace std;

class Student: public Person{
public:

    Student();
    Student(int newId,string newName, string newMajor, float newGpa, string newLevel, int newAdvisor);
    ~Student();

    //accessors
    string getMajor();
    float getGPA();
    string getLevel();
    int getAdvisor();

    //mutators
    void setID(int id);
    void setName(string n);
    void setMajor(string m);
    void setGPA(float g);
    void setLevel(string l);
    void setAdvisor(int a);
    string printPerson();
    
private:

   //implied id from inheritance
    //implied name from inheritance
    string major; //string - major
    float gpa; // float - GPA
    string level; //string - level
    int advisor; // int representing advisor ID
};



#endif
