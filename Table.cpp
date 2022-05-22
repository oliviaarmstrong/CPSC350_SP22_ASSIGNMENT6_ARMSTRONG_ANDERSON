#include "Table.hpp"
#include <fstream>
#include <vector>

Table::Table(){
    masterFaculty = new BST<Faculty*>();
    masterStudent =  new BST<Student*>();
    readFiles();
}


void Table::readFiles(){
    ifstream studentInput;
    ifstream facultyInput;

    studentInput.open("studentFile.txt");
    facultyInput.open("facultyFile.txt");

    if(studentInput.is_open()){
        readStudentFile(studentInput);
    }
    else{
        cout << "No student file to read, starting with empty Student tree" << endl;
    }

    if(facultyInput.is_open()){
        readFacultyFile(facultyInput);
    }
    else{
        cout << "No faculty file to read, starting with empty Faculty tree" << endl;
    }
}

//pass by reference on all ifstream and ofstream objects to prevent losing progress in reading/writing files
void Table::readStudentFile(ifstream &input){
  int currcount = 0;
  string currinput = "";
  while(input.peek()!=EOF){
    string filedata[6]; //array
    for(int i = 0; i < 6; ++ i){
      if (i == 5){
        getline(input, currinput, '\n');
        filedata[i] = currinput;

        int id = stoi(filedata[0]);

        string name = filedata[1];

        string major = filedata[2];

        float gpa = stof(filedata[3]);

        string level = filedata[4];

        int advisor = stoi(filedata[5]);

        for(int k = 0; k < 6; ++k){
          cout << filedata[k] << endl;
        }

        Student* stu = new Student(id, name, major, gpa, level, advisor);
        masterStudent->insert(stu);
        currcount = 0;
      }
        else{
            getline(input, currinput, '-');
            filedata[i] = currinput;
            ++currcount;
        }
    }
  }
  input.close();
}

//Reads the file containing faculty information
void Table::readFacultyFile(ifstream &input){
    int adviseeCount = 0;
    string currline = "";
    while(input.peek()!=EOF){
      string filedata[4]; //array
      GenList<int>* advisees = new GenList<int>();
      for(int i = 0; i < 5; ++i){
        if (i == 4){
          getline(input, currline, '-');
          int commas = 0;
          for(int k = 0; k < currline.length(); k++){
            if(currline[k] == ','){
              ++commas;
            }
          }
          string splitval = ",";
          string advisee = "";
          for(int o = 0; o < commas + 1; ++o){
            advisee = currline.substr(0, currline.find(splitval));
            cout << "Advisee: " << advisee << endl;
            advisees->append(stoi(advisee));
            currline.erase(0, currline.find(splitval) + splitval.length());
          }
        }
      else{
        getline(input, currline, '-');
        filedata[i] = currline;
      }
    }
    //int id = stoi(filedata[0]);
    int id  = 4;

    string name = filedata[1];

    string level = filedata[2];

    string department = filedata[3];

    cout << filedata[0] << endl;
    cout << filedata[1] << endl;
    cout << filedata[2] << endl;
    cout << filedata[3] << endl;

    Faculty* fac = new Faculty(id, name, level, department, advisees);
    masterFaculty->insert(fac);
  }
  input.close();
}

//Saves information to the files
void Table::saveToFiles(){
    ofstream studentOut("studentFile.txt");
    ofstream facultyOut("facultyFile.txt");

    masterStudent->treeToString(studentOut);
    masterFaculty->treeToString(facultyOut);
}


//option 1- Print all students and their information (sorted by ascending id #)
void Table::printStudents(){
    masterStudent->printInOrder();

}

//option 2- Print all faculty and their information (sorted by ascending id #)
void Table::printFaculty(){
    masterFaculty->printInOrder();

}

//option 3- Find and display student information given the students id
bool Table::studentFindAndDisplay(int studentId){
    if (findStudent(studentId) != NULL){
        cout << findStudent(studentId)->printPerson();
    }
    else {
        cout << "Student does not exist." << endl;
    }
    return false;
}

//option 4- Find and display faculty information given the faculty id
bool Table::facultyFindAndDisplay(int facultyId){
    if(findFaculty(facultyId) != NULL) {
        cout << findFaculty(facultyId)->printPerson();
    }
    return false;
}

//option 5- Given a student’s id, print the name and info of their faculty advisor
void Table::showAdvisor(int studentId){
    if (findStudent(studentId) != NULL){
        Student* s = findStudent(studentId);
        Faculty* f = findFaculty(s->getAdvisor());
        cout << f->printPerson();
    }
}

//option 6- Given a faculty id, print ALL the names and info of his/her advisees.
void Table::printAllAdvisees(int facultyId){
    if(findFaculty(facultyId) != NULL) { // check to see if valid ID is given
        Faculty* f = findFaculty(facultyId); //finding the faculty node in master list corresponding w/ ID to access object refrence
        ListNode<int>* curr; //temp listnode to keep track of position in advisee list, so we can index through and get each student
        curr = f->getAdviseeList()->getFront(); //set curr to begining of advisee list
        while(curr!= NULL){//loop through list
            Student* s = findStudent(curr->data); //given the current data of the node from advisee list, find student within the master list and store the object within a temporary student object
            s->printPerson();//print out data of student object
            curr = curr->next; //index to next student ID of facualty advisee list
        }
    }
}

//option 7- Add a new student
bool Table::addStudent(){
    int id;
    cout << "id: ";
    cin >>id;
    if(findStudent(id) != NULL){
        cout << "Student with ID already exists.";
        return false;
    }
    else{
        string name;
        cout << "name: ";
        cin >>name;

        string major;
        cout << "major: ";
        cin >> major;

        double gpa;
        cout << "gpa: ";
        cin >> gpa;

        string level;
        cout << "level:";
        cin >> level;

        int advisor;
        cout << "advisor: ";
        cin >> advisor;

        while(findFaculty(advisor) == NULL){ //returning null means advisor doesnt exist, have user choose another option.
            cout << "That faculty id doesnt exist, please add a new faculty member or try again." << endl;
            return false;
        }

        Student* stu = new Student(id, name, major, gpa, level, advisor);

        masterStudent->insert(stu);
        return true;
    }
}

//option 9- Add a new faculty member
bool Table::addFaculty(){

    int id;
    cout << "id: ";
    cin >> id;

    string name;
    cout << "name: ";
    cin >> name;

    string level;
    cout << "level: ";
    cin >> level;

    string department;
    cout << "department: ";
    cin >> department;

    GenList<int>* AdviseeList = new GenList<int>();

      Faculty* f = new Faculty(id, name, level, department, AdviseeList);

      masterFaculty->insert(f);

    return false;


}

//option 8- Delete a student given the ID
bool Table::deleteStudent(int id){
    if(findStudent(id) != NULL){ //if student exists
        Student* s = findStudent(id); //get student object from master list using given ID
        Faculty* f = findFaculty(s->getAdvisor()); //get and find the advisor object of student + store it
        f->getAdviseeList()->findAndDelete(s->getID());
        masterStudent->deleteNode(s);
    }
    return false;
}

//option 10- Delete a faculty given ID
bool Table::deleteFaculty(int id){
  if(findFaculty(id) != NULL){
    Faculty* f = findFaculty(id);
    GenList<int>* al = f->getAdviseeList();
    while(!al->isEmpty()){
      int newFacID = 0;
      int randFac = -1;
      TreeNode<Faculty*>* newFac = masterFaculty->getRoot();
      while(randFac!= 0){
        randFac = rand() % 3;
        if(randFac == 0 && newFac->left != NULL){
          newFac = newFac->left;
        }
        else if(randFac == 1 && newFac->right != NULL){
          newFac = newFac->right;
        }
        else{
          newFacID = newFac->key->getID();
          break;
        }
      }
      findStudent(al->remove())->setAdvisor(newFacID);
    }
  }
    return false;
}

//option 11- Change a students advisor given student id and new faculty id
bool Table::changeAdvisor(int studentId, int newAdvisor){
  Student* stu = new Student(); //new student
  if(findStudent(studentId) != NULL && findFaculty(newAdvisor) != NULL) { //if that student id exists, if the new faculty exists
    stu=findStudent(studentId); //find that student
    findFaculty(stu->getAdvisor())->getAdviseeList()->findAndDelete(studentId); //find the curr advisor of         that student, go to their advisee list and delete that student off their list
    stu->setAdvisor(newAdvisor); //replace student's advisor with new advisor
    findFaculty(stu->getAdvisor())->getAdviseeList()->append(studentId); //go to that new advisor and add          student to their Advisee List
  }
    return false;
}


//option 12 - Remove an advisee from a faculty member given the ids
bool Table::removeAdvisee(int facultyId, int studentId){
  if(findFaculty(facultyId) != NULL && findStudent(studentId) != NULL){
    findFaculty(facultyId)->getAdviseeList()->findAndDelete(studentId); //finds faculty and removes advisee from its list
    TreeNode<Faculty*>* newFac = masterFaculty->getRoot(); //tree node start for indexing
    int randFac = -1;
    int newFacID = 0;
    while(randFac!= 0){
      randFac = rand() % 3;
      if(randFac == 0 && newFac->left != NULL){
        newFac = newFac->left;
      }
      else if(randFac == 1 && newFac->right != NULL){
        newFac = newFac->right;
      }
      else{
        newFacID = newFac->key->getID();
        break;
      }
    }
    findStudent(studentId)->setAdvisor(newFacID);
  }//finds the student and assigns new faculty
  return false;
}

//Find a student in the BST given the id
Student* Table::findStudent(int id){
    TreeNode<Student*>* root = masterStudent->getRoot();
    if(root == NULL) {
        return NULL;
    }
    TreeNode<Student*>* curr = root;
    while(curr->key->getID() != id){
        if(curr->key->getID() < id){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
        if(curr == NULL){
            return NULL;
        }
    }
    return curr->key;
}

//Find a faculty member in the BST given the id
Faculty* Table::findFaculty(int id){
    TreeNode<Faculty*>* root = masterFaculty->getRoot();
    if(root == NULL) {
        return NULL;
    }
    TreeNode<Faculty*>* curr = root;
    while(curr->key->getID() != id){
        if(curr->key->getID() < id){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
        if(curr == NULL){
            return NULL;
        }
    }
    return curr->key;
    }
