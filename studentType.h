#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "personType.h"
#include "professorType.h"
#include "courseType.h"

using namespace std;

class studentType : public personType {
public:
    studentType();
    studentType(string setfName, string setlName);
    studentType(string setfName, string setlName, string setAddress, string setDOB, double setHeight, char setGender, string id, double gpa, string classification);
    void setID(string id);
    void setGPA(double gpa);
    void setClassification(string classification);
    void setCoursePos(int courseNumberPosition);
    string getID();
    double getGPA();
    string getClassification();
    int* getCoursePos();
    int getNumCourses();

    virtual void print(int value);
    bool equals(personType person[], personType personTwo[], const int SIZE) const;


    bool addCourse(courseType **&courses, const int pos, int& courseTypeSIZE);

    void setNumCourses(int number);
    void incrementNumCourses();
    void printother(int value);
courseType **studentCourses = new courseType*[maxCourses];
private:
    string id;
    double gpa;
    string classification;
    int numCourses = 0;
    const int maxCourses = 5;
    int *coursePos;
    //courseType* courses;

    //studentCourses[numCourses] = new courseType( tempSectionID, tempCourseName, tempTitle, tempDays, tempTime, tempRoom, tempCap);
};
#endif