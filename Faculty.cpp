#include "Faculty.hpp"


Faculty::Faculty() : Person(){
    level = "";
    department = "";
    advisees = NULL;
}

Faculty::Faculty(int id, string n, string l, string d, GenList<int>* list) : Person(n, id){
    
    level = l;
    department = d;
    advisees = list;
}

string Faculty::getLevel(){
    return level;
}

string Faculty::getDepartment(){
    return department;
}

GenList<int>* Faculty::getAdviseeList(){
    return advisees;
}

void Faculty::setLevel(string l){
    level = l;
}

void Faculty::setDepartment(string d){
    department = d;
}

void Faculty::setAdviseeList(GenList<int>* list){
    advisees = list;
}


string Faculty::printPerson(){
    string str = "";
    str += to_string(getID());
    str += "\n" + getName();
    str += "\n" + level;
    str += "\n" + department;
    str += "\n" + advisees->toString() + "\n";
    return str;
}

