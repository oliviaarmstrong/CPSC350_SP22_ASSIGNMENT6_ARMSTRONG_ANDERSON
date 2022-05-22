#ifndef Table_hpp
#define Table_hpp

#include "BST.hpp"
#include "Student.hpp"
#include "Faculty.hpp"

class Table{
public:
    Table();//default
    //Tables(BST<Student*>* stu, BST<Faculty*>* fac);//overloaded
    
    void printStudents(); //all their info, sorted by ascending ID #
    void printFaculty(); //all their info, sorted by ascending ID #
    
    void readStudentFile(ifstream &input);
    void readFacultyFile(ifstream &input);
    void readFiles();
    void saveToFiles();
    
    bool studentFindAndDisplay(int studentId);
    bool facultyFindAndDisplay(int facultyId);
    void showAdvisor(int studentId);
    void printAllAdvisees(int facultyId);
    bool addStudent();
    bool addFaculty();
    bool deleteStudent(int id);
    bool deleteFaculty(int id);
    bool changeAdvisor(int studentId, int newAdvisor);
    bool removeAdvisee(int facultyId, int studentId);
    
    //TODO
    void rollback();
    
    //utilities/helper functions
    Student* findStudent(int id);
    Faculty* findFaculty(int id);
    void printVector(vector<string> vect);
    
private:
    BST<Student*>* masterStudent; //tree of student objects
    BST<Faculty*>* masterFaculty; //tree of faculty objects
    
};
#endif


