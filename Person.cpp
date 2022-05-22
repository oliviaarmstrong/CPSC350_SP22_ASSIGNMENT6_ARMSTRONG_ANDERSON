
#include "Person.hpp"


Person::Person(){
  name = "";
  id = -1;
}

Person::Person(string newName, int newId){
  name = newName;
  id = newId;
}

int Person::getID(){
  return id;
}

string printPerson(){
    return  "Person";
}

string Person::getName(){
  return name;
}
void Person::setID(int newId){
  id = newId;
}

void Person::setName(string newName){
  name = newName;
}

bool Person::operator==(const Person& right){
    if(id == right.id){
        return true;
    }
    return false;
}

bool Person::operator<(const Person& right){
    if(id < right.id){
        return true;
    }
    return false;
}

bool Person::operator>(const Person& right){
    if(id > right.id){
        return true;
    }
    return false;
}

bool Person::operator<=(const Person& right){
    if(id <= right.id){
        return true;
    }
    return false;
}

bool Person::operator>=(const Person& right){
    if(id >= right.id){
        return true;
    }
    return false;
}

