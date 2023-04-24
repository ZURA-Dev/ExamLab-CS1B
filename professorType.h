#ifndef PROFESSORTYPE_H
#define PROFESSORTYPE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "personType.h"
#include "courseType.h"


using namespace std;

class professorType : public personType{
private:
string employeeID;
string department;
string degree;
int numCrsTaught;
int maxCrsTaught = 3;
//int numCoursesTaught;
int *coursePos;
int numCourses = 0;
courseType *professorCourses = new courseType[maxCrsTaught];

public:
professorType();
professorType(string fName, string lName);
professorType(string fName, string lName, string address, string dob, double height, char gender);
professorType(string fName, string lName, string address, string dob, double height, char gender, string employeeid, string department, string degree);
//setters getters
void setEmployeeID(string employeeID);
void setDepartment(string department);
void setDegree(string degree);
void setCoursePos(int courseNumberPosition);
string getEmployeeID();
string getDepartment();
string getDegree();
 int* getCoursePos();
void createProfessor(professorType* professor);

//others
void print(int value);
void assignCourse(courseType **&courses, const int pos, int& courseTypeSIZE);



};





#endif