#include <iostream>
#include "Simulation.hpp"
using namespace std;

Simulation::Simulation(){
}

void Simulation::printMenu(){
    

    cout << "Choice: ";
}

void Simulation::simulate(){
    Table records = Table();
    int choice;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
            case 1:
            {
                records.printStudents();
                break;
            }
            case 2:
            {
                records.printFaculty();
                break;
            }
            case 3:
            {
                int id;
                cin >> id;
                records.studentFindAndDisplay(id);
                break;
            }
            case 4:
            {
                int id;
                cin >> id;
              records.facultyFindAndDisplay(id);
                break;
            }
            case 5:
            {
                int id;
                cin >> id;
              records.showAdvisor(id);
                break;
            }
            case 6:
            {
                int id;
                cin >> id;
              records.printAllAdvisees(id);
                break;
            }
            case 7:
            {
              records.addStudent();
                break;
            }
            case 8:
            {
                int id;
                cin >> id;
              records.deleteStudent(id);
                break;
            }
            case 9:
            {
              records.addFaculty();
                break;
            }
            case 10:
            {
                int id;
                cin >> id;
              records.deleteFaculty(id);
                break;
            }
            case 11:
            {
                int id;
                cin >> id;
                int advisor;
                cin >> advisor;
              records.changeAdvisor(id, advisor);
                break;
            }
            case 12:
            {
                int FacId;
                cin >> FacId;
                int StuId;
                cin >> StuId;
              records.removeAdvisee(FacId, StuId);
                break;
            }
            case 13:
            {
              //rollback
                break;
            }
            case 14:
            {
              //exit
                break;
            }
            default:
            {
                cout << "Invalid choice, please enter a number between 1 and 14.";
                break;
            }
        }




    } while (choice != 14);


    records.saveToFiles();
}
