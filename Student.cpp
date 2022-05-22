#include "Student.hpp"

Student::Student() : Person(){
  major = "";
  gpa = 0.0;
  advisor = -1;
}

//pass through id and name to Person
Student::Student(int newId,string newName, string newMajor, float newGpa, string newLevel, int newAdvisor) : Person(newName, newId){
  major = newMajor;
  gpa = newGpa;
  level = newLevel;
  advisor = newAdvisor;
}

Student::~Student(){
  //TODO
}

string Student::getMajor(){
  return major;
}

float Student::getGPA(){
  return gpa;
}

string Student::getLevel() {
  return level;
}

int Student::getAdvisor(){
  return advisor;
}

void Student::setMajor(string newMajor){
  major = newMajor;
}

void Student::setGPA(float newGpa){
  gpa = newGpa;
}

void Student::setLevel(string newLevel) {
  level = newLevel;
}

void Student::setAdvisor(int newAdvisor){
  advisor = newAdvisor;
}

string Student::printPerson(){
    string result = "";
    result += to_string(getID());
    result += "\n" + getName();
    result += "\n" + major;
    result += "\n" + to_string(gpa);
    result += "\n" + level;
    result += "\n" + to_string(advisor);
    result += "\n";
    return result;

}
