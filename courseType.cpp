#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "courseType.h"

#include "personType.h"

using namespace std;
//constructor
//initialize census
int courseType::census;


courseType::courseType(){
    sectionID = "empty";
    courseName = "empty";
    title = "empty";
    days = "empty";
    time = "empty";
    room = "empty";
    status = false;
    cap = 0;
    enrolled = 0;
    census = 0;
}
courseType::courseType(string sectionID, string courseName, string title, string days, string time, string room, int cap){
    this->sectionID = sectionID;
    this->courseName = courseName;
    this->title = title;
    this->time = time;
    this->room = room;
    this->cap = cap;
    status = false;
    enrolled = 0;
    census = 0;
}
courseType::courseType(string sectionID, string courseName, string title, string days, string time, string room, bool status, int cap, int enrolled, int census){
    this->sectionID = sectionID;
    this->courseName = courseName;
    this->title = title;
    this->time = time;
    this->room = room;
    this->cap = cap;
    this->status = status;
    this->enrolled = enrolled;
    this->census = census;
}

//getters
string courseType::getSectionID(){return sectionID;}
string courseType::getCourseName(){return courseName;}
string courseType::getTitle(){return title;}
string courseType::getDays(){return days;}
string courseType::getTime(){return time;}
string courseType::getRoom(){return room;}
bool courseType::getStatus(){return status;}
int courseType::getCap(){return cap;}
int courseType::getEnrolled(){return enrolled;}
int courseType::getCensus(){return census;}
//setters
void courseType::setSectionID(string sectionID){this->sectionID = sectionID;}
void courseType::setCourseName(string courseName){this->courseName = courseName;}
void courseType::setTitle(string title){this->title = title;}
void courseType::setDays(string days){this->days = days;}
void courseType::setTime(string time){this->time = time;}
void courseType::setRoom(string room){this->room = room;}
void courseType::setStatus(bool status){this->status = status;}
void courseType::setCap(int cap){this->cap = cap;}
void courseType::setEnrolled(int enrolled){this->enrolled = enrolled;}
void courseType::setCensus(int census){courseType::census = census;}
void courseType::print(courseType **&courses, int& courseTypeSIZE , int value)
{
string status = "empty";
int getCap = courses[value]->getCap();
int getEnrolled = courses[value]->getEnrolled();

bool boolStatus = courses[value]->getStatus();
if (getEnrolled < getCap){
    status = "OPEN";
}else if (getEnrolled >= getCap){
    status = "CLOSED";
}

    cout << "COURSE #: " << value << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << setw(10) <<  left << "Section ID" 
    << setw(1) << left << " "
    << setw(11) << left <<  "Course Name" 
    << setw(1) << left << " "
    << setw(5) << left <<  "Title" 
    << setw(30) << left << "                              "
    << setw(4)<< left <<  "Days" 
    << setw(1) << left << " "
    << setw(4) <<  left<< "Time" 
    << setw(30) << left << "                              "
    << setw(3)<<left << "Cap" 
    << setw(1) << left << " "
    << setw(8)<<left << "Enrolled" 
    << setw(1) << left << " "
    << setw(6)<< left <<"Status" << endl;
    cout << setw(10) << left <<"==========" 
         << setw(1) << left << " "
         << setw(11) << left << "===========" 
         << setw(1) << left << " "
         << setw(5) << left << "=====" 
         << setw(30) << left << "                              "
         << setw(4) << left << "====" 
         << setw(1) << left << " "
         << setw(17)<< left  << "=================" 
         << setw(17) << left << "                 "
         << setw(3) << left << "===" 
         << setw(1) << left << " "
         << setw(8) << left << "========" 
         << setw(1) << left << " "
         << setw(6) << left << "======" << endl;
        cout << setw(10) << left << courses[value]->getSectionID() 
        << setw(1) << left << " "
        <<setw(10) << left <<  courses[value]->getCourseName() 
        << setw(1) << left << " "
        << setw(15) << left << courses[value]->getTitle() 
        << setw(15) << left << "               "
        << setw(5)<< left << courses[value]->getDays() 
        << setw(1) << left << " "
        << setw(19) << left << courses[value]->getTime()
        << setw(17) << left << "                    "
        << setw(3) << left << courses[value]->getCap()
        << setw(1) << left << " "
        << setw(8) << left << courses[value]->getEnrolled()
        << setw(1) << left << " "
        << setw(6) << left << status << endl;
  
}

/*void courseType::addCourses(){
    cout << "\033c";
    string tempSectionID;
    string tempCourseName;
    string tempTitle;
    string tempDays;
    string tempTime;
    string tempRoom;
    bool tempStatus;
    int tempCap;
    int tempEnrolled;
    int tempCensus;
    int answer;
    for(int i = 0; i < sizeof(courses); i++){
        cout << "Course Section ID (i.e. 14295): ";
        cin >> tempSectionID;
        cin.ignore();
        cout << endl;
        cout << "Course Name (i.e. CS1B): ";
        cin >> tempCourseName;
        cin.ignore();
        cout << endl;
        cout << "Course Title (i.e. INTRO TO CS I): ";
        cin >> tempTitle;
        cin.ignore();
        cout << endl;
        cout << "Course Days (i.e. MW,TTh, MWF): ";
        cin >> tempDays;
        cin.ignore();
        cout << endl;
        cout << "Course Time (i.e. 5:50 PM - 7:45 PM): ";
        cin >> tempTime;
        cin.ignore();
        cout << endl;
        cout << "Room (i.e. SM 202): ";
        cin >> tempRoom;
        cin.ignore();
        cout << endl;
        cout << "Cap (i.e. 30): ";
        cin >> tempCap;
        cin.ignore();
        cout << endl;
        cout << endl;
        cout << "1. Would you like to enter more?" << endl;
        cout << "2. exit without saving" << endl;
        cout << "3. exit and save" << endl;
        cin >> answer;
        cin.ignore();
        if (answer == 2){
            return;
        }
        if(answer == 3){
            courses[i].setSectionID(tempSectionID);
            courses[i].setCourseName(tempCourseName);
            courses[i].setTitle(tempTitle);
            courses[i].setDays(tempDays);
            courses[i].setTime(tempTime);
            courses[i].setRoom(tempRoom);
            courses[i].setCap(tempCap);
            return;
        }
    }
}*/
//bool courseType::enrollStudent(){}

