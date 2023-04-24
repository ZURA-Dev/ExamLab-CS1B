#ifndef COURSETYPE_H
#define COURSETYPE_H



#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>

#include "personType.h"


class courseType {
private:
string sectionID;
string courseName;
string title;
string days;
string time;
string room;
bool status; //true means open, false means closed
int cap;
int enrolled = 0;
static int census;

public:
//constructor

courseType();
courseType(string sectionID, string courseName, string title, string days, string time, string room, int cap);
courseType(string sectionID, string courseName, string title, string days, string time, string room, bool status, int cap, int enrolled, int census);
//getters
string getSectionID();
string getCourseName();
string getTitle();
string getDays();
string getTime();
string getRoom();
bool getStatus();
int getCap();
int getEnrolled();
static int getCensus();
//setters
void setSectionID(string sectionID);
void setCourseName(string courseName);
void setTitle(string title);
void setDays(string days);
void setTime(string time);
void setRoom(string room);
void setStatus(bool status);
void setCap(int cap);
void setEnrolled(int enrolled);
static void setCensus(int census);
void print(courseType **&courses, int& courseTypeSIZE , int value);
//void addCourses(){}

bool enrollStudent();

};

#endif
