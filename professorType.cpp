#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "professorType.h"
#include "personType.h"
#include "courseType.h"
using namespace std;


professorType::professorType(){};
professorType::professorType(string fName, string lName){
    personType::setfName(fName);
    personType::setlName(lName);
};
professorType::professorType(string fName, string lName, string address, string dob, double height, char gender){
    personType::setfName(fName);
    personType::setlName(lName);
    personType::setAddress(address);
    personType::setHeight(height);
    personType::setDOB(dob);
    personType::setGender(gender);
};
professorType::professorType(string fName, string lName, string address, string dob, double height, char gender, string employeeid, string department, string degree){
    personType::setfName(fName);
    personType::setlName(lName);
    personType::setAddress(address);
    personType::setHeight(height);
    personType::setDOB(dob);
    personType::setGender(gender);
    setEmployeeID(employeeid);
    setDepartment(department);
    setDegree(degree);
    
};

void professorType::setEmployeeID(string employeeID){this->employeeID = employeeID;}
void professorType::setDepartment(string department){this->department = department;}
void professorType::setDegree(string degree){this->degree = degree;}
void professorType::setCoursePos(int courseNumberPosition){coursePos = new int[courseNumberPosition];}
string professorType::getEmployeeID(){return employeeID;}
string professorType::getDepartment(){return department;}
string professorType::getDegree(){return degree;}
int* professorType::getCoursePos(){return coursePos;}
void professorType::createProfessor(professorType* professor){
    string tempEmployeeID;
    string tempDepartment;
    string tempDegree;
}

//other
void professorType::print(int value)
    {
cout << endl;
        //cout << "studentType Print:" << endl;

        cout << "Printing Professor # " << value << ": " << setw(10) << "--------------" << endl
             << endl;
    cout <<setw(20) << left << "Name" 
    << setw(15) << left << "               "
    << setw(20) << left <<  "Address" 
    << setw(20) << left << "                    "
    << setw(6)<< left <<  "Height" 
    << setw(1) << left << " "
    << setw(15) <<  left<< "DOB" 
    << setw(1) << left << " "
    << setw(6)<<left << "Gender" 
    <<endl;    
    cout << setw(20)<< left << "====================" 
    << setw(15) << left << "               "
    << setw(20) << left <<  "====================" 
    << setw(20) << left << "                    "
    << setw(6)<< left <<  "======" 
    << setw(1) << left << " "
    << setw(15) <<  left<< "===============" 
    << setw(1) << left << " "
    << setw(6)<<left << "======" << endl;

    cout << setw(10) << left <<  getfName() 
    << setw(1)<< left << " " << setw(9)<< left << getlName() 
    << setw(15) << left << "               "
    << setw(20) << left <<  getAddress()
    << setw(20) << left << "                    "
    << setw(6)<< left <<  getHeight()
    << setw(1) << left << " "
    << setw(15) <<  left<< getDOB()
    << setw(1) << left << " "
    << setw(6)<<left << getGender()
    <<endl;
       /* cout << "First Name: " << getfName() << endl;
        cout << "Last Name: " << getlName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Height: " << getHeight() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Date of Birth: " << getDOB() << endl;
        cout << "ID:  " << getID() << endl;
        cout << "GPA:  " << getGPA() << endl;
        cout << "Classification: " << getClassification() << endl;*/
    }

void professorType::assignCourse(courseType **&courses, const int pos, int& courseTypeSIZE){
    //this is just a simple function, all i need to do is have a paramaters of the courses, studentCourses, and value (position of courses), grab the position of courses, add to studentCourses and +1 to enrollment.
        // check if cap is hit, if its hit give out an error class full.
        //could add a safety check to make sure student cant enroll twice into one class?????

        int numCoursesPrevious;
        //int censusNum = courseType::getCensus();
        //censusNum += 1;
        if(numCrsTaught < maxCrsTaught){
           // int enrolledNumber = courses[pos]->getEnrolled();
            cout << "Assigning Professor into class #" << pos << endl;
            //courses[pos]->setEnrolled(getEnrolledNumber);

            //courseType::setCensus(censusNum);
            courses[pos]->print(courses, courseTypeSIZE, pos);
            //professorCourses[numCourses++] = courses[pos];
            cout << endl;


            numCoursesPrevious = numCourses;
            numCoursesPrevious -= 1;
            cout << professorCourses[numCoursesPrevious].getSectionID();
            cout << professorCourses[numCourses].getTitle();


            system("pause");
        }else{
            cout << "Exceed the maximum amount of classes! || or CLASS Cap has been hit!" << endl;
            system("pause");
            //return false;
        }
}
