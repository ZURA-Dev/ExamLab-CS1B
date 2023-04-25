#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "studentType.h"
#include "professorType.h"
#include "personType.h"
#include "courseType.h"


using namespace std;
    studentType::studentType(){};
    studentType::studentType(string fName, string lName)
    {
        setfName(fName);
        setlName(lName);
    };
    studentType::studentType(string setfName, string setlName, string setAddress, string setDOB, double setHeight, char setGender, string id, double gpa, string classification)
    {
        string fName = setfName;
        string lName = setlName;
        string address = setAddress;
        double height = setHeight;
        string dob = setDOB;
        char gender = setGender;
        personType::setfName(fName);
        personType::setlName(lName);
        personType::setAddress(address);
        personType::setHeight(height);
        personType::setDOB(dob);
        personType::setGender(gender);
        this->gpa = gpa;
        this->classification = classification;
        this->id = id;
    };
    void studentType::setID(string id) { this->id = id; }
    void studentType::setGPA(double gpa) { this->gpa = gpa; }
    void studentType::setClassification(string classification) { this->classification = classification; }
    void studentType::setCoursePos(int courseNumberPosition){coursePos = new int[courseNumberPosition];}
    string studentType::getID() { return id; }
    double studentType::getGPA() { return gpa; }
    string studentType::getClassification() { return classification; }
    int* studentType::getCoursePos(){return coursePos;}
    int studentType::getNumCourses(){return numCourses;}

    void studentType::print(int value)
    {
        

        //cout << "studentType Print:" << endl;

        cout << "Printing Student # " << value << ": " << setw(10) << "--------------" << endl
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

    cout << setw(10) << left << getfName() 
    << setw(1)<< left << " " << setw(9)<< left << getlName() 
    << setw(15) << left << "               "
    << setw(20) << left <<  getAddress()
    << setw(20) << left << "                    "
    << setw(6)<< left <<  getHeight()
    << setw(1) << left << " "
    << setw(15) <<  left<< getDOB()
    << setw(1) << left << " "
    << setw(6)<<left << getGender() << endl;
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
    void studentType::printother(int value){
         cout <<setw(10) << left << "ID" 
    << setw(1) << left << " "
    << setw(14) << left <<  "Classification" 
    << setw(1) << left << " "
    << setw(11)<< left <<  "Course Load" 
    << setw(1) << left << " "
    << setw(3)<< left <<  "GPA" 
    <<endl;    
    cout << setw(10)<< left << "==========" 
    << setw(1) << left << " "
    << setw(14) << left <<  "==============" 
    << setw(1) << left << " "
    << setw(11)<< left <<  "=========="
    << setw(1) << left << " "
    << setw(3)<< left <<  "==="  << endl;

    cout << setw(10) << left << getID() 
    << setw(1)<< left << " " 
    << setw(14)<< left << getClassification() 
    << setw(1) << left << " "
    << setw(20) << left <<  numCourses
    << setw(20) << left << "                    "
    << setw(3)<< left <<  getGPA()
    <<endl;
    }
    bool studentType::equals(personType person[], personType personTwo[], const int SIZE) const 

    {
        int pos = 0;
        for (int i = 0; i < SIZE; i++)
        {
            if (person[i].getfName() == personTwo[i].getfName() && person[i].getlName() == personTwo[i].getlName() && person[i].getAddress() == personTwo[i].getAddress() && person[i].getHeight() == personTwo[i].getHeight() && person[i].getDOB() == personTwo[i].getDOB() && person[i].getGender() == personTwo[i].getGender())
            {
                pos++;
            }
            if (pos == SIZE)
            {
                cout << "identical!" << endl;
                cout << "Everything matches" << endl;
            }
        }
        system("pause");
        return true;
    }
    bool studentType::addCourse(courseType **&courses, const int pos, int& courseTypeSIZE){
        //this is just a simple function, all i need to do is have a paramaters of the courses, studentCourses, and value (position of courses), grab the position of courses, add to studentCourses and +1 to enrollment.
        // check if cap is hit, if its hit give out an error class full.
        //could add a safety check to make sure student cant enroll twice into one class?????
        int checkEnrolled = courses[pos]->getEnrolled();
        int checkCap = courses[pos]->getCap();
        int numCoursesPrevious;
        int getEnrolledNumber = courses[pos]->getEnrolled();
        getEnrolledNumber++;
        int censusNum = courseType::getCensus();
        censusNum += 1;
        if(numCourses < maxCourses && checkEnrolled < checkCap){
            int enrolledNumber = courses[pos]->getEnrolled();
            cout << "Enrolling into class #" << pos << endl;
            courses[pos]->setEnrolled(getEnrolledNumber);

            courseType::setCensus(censusNum);
            courses[pos]->print(courses, courseTypeSIZE, pos);
            studentCourses[numCourses] = courses[pos];
            numCourses += 1;
            cout << endl;


            //numCoursesPrevious = numCourses;
           // numCoursesPrevious -= 1;
            //cout << studentCourses[numCoursesPrevious]->getSectionID();
           //cout << studentCourses[numCourses]->getTitle();
           return true;

        }else{
            cout << "Exceed the maximum amount of classes! || or CLASS Cap has been hit!" << endl;
            system("pause");
            //return false;
        }
     }


    void studentType::setNumCourses(int number){}
    void studentType::incrementNumCourses(){}