//----------------------------------
// File Name: ExamLab2
// Project Name: Exam Lab 2
// ---------------------------------
// Creator's name and email: Timothy Ropac, tropac0@saddleback.edu
// Course-Section: CS 1B
// Creation Date: 4/20
// Date of Last Modification: 4/21
// ---------------------------------
// Purpose:
// Getting use to pointers, classes, objects, dynamic arrays and passing these into functions and managing data
// ---------------------------------
// Algorithm:
// Creating a way for students and professors to organize/create/enroll into clases
// ---------------------------------


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "personType.h"
#include "studentType.h"
#include "professorType.h"
#include "courseType.h"

using namespace std;

void addCourses(courseType **&courses, int &courseTypeSIZE)
{

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


    cout << "Course Section ID (i.e. 14295): ";
    getline(cin, tempSectionID);

    cout << endl;
    cout << "Course Name (i.e. CS1B): ";
    getline(cin, tempCourseName);

    cout << endl;
    cout << "Course Title (i.e. INTRO TO CS I): ";
    getline(cin, tempTitle);

    cout << endl;
    cout << "Course Days (i.e. MW,TTh, MWF): ";
    cin >> tempDays;
    cin.ignore();

    cout << endl;
    cout << "Course Time (i.e. 5:50 PM - 7:45 PM): ";
    getline(cin, tempTime);
    cout << endl;
    cout << "Room (i.e. SM 202): ";
    getline(cin, tempRoom);

    cout << endl;
    cout << "Cap (i.e. 30): ";
    cin >> tempCap;
    cout << endl;

    courses[courseTypeSIZE] = new courseType(tempSectionID, tempCourseName, tempTitle, tempDays, tempTime, tempRoom, tempCap);
    courseTypeSIZE += 1;
    
  
}
void createPerson(personType **&person, studentType **&student, professorType **&professor, int &studentTypeSIZE, int &professorTypeSIZE, int &personTypeSIZE)
{
  // int count;

  // put this into a switch;;;;;;;;;;;
  string tempfName;
  string templName;
  string tempAddress;
  double tempHeight;
  string tempDOB;
  char tempGender;
  string tempID;
  double tempGPA;
  string tempClassification;
  int tempNumCourses;
  string tempEmployeeID;
  string tempDepartment;
  string tempDegree;
  int tempNumCRSTaught;

  int answer;
  cout << "\033c";
  cout << "Who do you want to create?" << endl;
  cout << "<1> personType" << endl;
  cout << "<2> studentType" << endl;
  cout << "<3> professorType" << endl;
  cout << "<4> EXIT" << endl;
  cin >> answer;
  cin.ignore();
  if (answer == 1)
  {
    cout << "First Name: ";
    getline(cin, tempfName);
    cout << endl;

    cout << "Last Name:";
    getline(cin, templName);
    cout << endl;

    cout << "Address: ";
    getline(cin, tempAddress);
    cout << endl;

    cout << "DOB: ";
    getline(cin, tempDOB);
    cout << endl;
    cout << "Height: ";
    cin >> tempHeight;
    cout << endl;
    cin.ignore();
    cout << "Gender (M/F): ";
    cin >> tempGender;
    cout << endl;
    cin.ignore();
    person[personTypeSIZE] = new personType(tempfName, templName,tempAddress, tempDOB, tempHeight, tempGender);
    personTypeSIZE += 1;
  }
  else if (answer == 2)
  {
    cout << "First Name: ";
    getline(cin, tempfName);
    cout << endl;

    cout << "Last Name:";
    getline(cin, templName);
    cout << endl;

    cout << "Address: ";
    getline(cin, tempAddress);
    cout << endl;

 cout << "Date of Birth: ";
    getline(cin, tempDOB);
    cout << endl;

    cout << "Height: ";
    cin >> tempHeight;
    cout << endl;

    cout << "Gender (M/F): ";
    cin >> tempGender;
    cout << endl;
    cin.ignore();
    cout << "ID: ";
    cin >> tempID;
    cout << endl;
    cin.ignore();
    cout << "GPA: ";
    cin >> tempGPA;
    cout << endl;
    cin.ignore();
    cout << "Classification: ";
    getline(cin, tempClassification);

    cout << endl;
    student[studentTypeSIZE] = new studentType(tempfName, templName, tempAddress, tempDOB, tempHeight, tempGender, tempID, tempGPA, tempClassification);
    studentTypeSIZE += 1;
  }

  else if (answer == 3)
  {
    cout << "First Name: ";
    getline(cin, tempfName);
    cout << endl;
    cin.ignore();
    cout << "Last Name:";
    getline(cin, templName);
    cout << endl;
    cin.ignore();
    cout << "Address: ";
    getline(cin, tempAddress);
    cout << endl;
    cin.ignore();

    cout << "Date of Birth: ";
    getline(cin, tempDOB);
    cout << endl;
    cin.ignore();

    cout << "Height: ";
    cin >> tempHeight;
    cout << endl;
    cin.ignore();

    cout << "Gender (M/F): ";
    cin >> tempGender;
    cout << endl;
    cin.ignore();
    cout << "employeeID: ";
    cin >> tempEmployeeID;
    cout << endl;
    cin.ignore();
    cout << "Department: ";
    cin >> tempDepartment;
    cout << endl;
    cin.ignore();
    cout << "Degree: ";
    getline(cin, tempDegree);
    cout << endl;
    cin.ignore();
    professor[professorTypeSIZE] = new professorType(tempfName, templName, tempAddress, tempDOB, tempHeight, tempGender, tempEmployeeID, tempDepartment, tempDegree);
    professorTypeSIZE += 1;
  }
  else
  {
    return;
  }
}

void enrollStudent(studentType **&student, courseType **&courses, int &studentTypeSIZE, int &courseTypeSIZE)
{
  int answer;
  int courseAnswer;
  cout << "\033c";
  for (int i = 0; i < studentTypeSIZE; i++)
  {
    student[i]->print(i);
  }
  cout << "select student #: ";
  cin >> answer;
  cout << endl;
  if (answer >= 0 && answer < studentTypeSIZE)
  {
    cout << "you have selected student #: " << answer << endl;
    cout << "Now select a course - > - > - >" << endl;
    for (int i = 0; i < courseTypeSIZE; i++)
    {
      courses[i]->print(courses, courseTypeSIZE, i);
    }
    cout << "Select course #: ";
    cin >> courseAnswer;
    cout << endl;
    if (courseAnswer >= 0 && courseAnswer < courseTypeSIZE)
    {
      student[answer]->addCourse(courses, courseAnswer, courseTypeSIZE);
    }
    else
    {
      cout << "error try a different number";
      system("pause");
      return;
    }
  }
  else
  {
    cout << "error try a different number";
    system("pause");
    return;
  }
}

void assignProfessor(professorType **&professor, courseType **&courses, int &professorTypeSIZE, int &courseTypeSIZE)
{
  int answer;
  int courseAnswer;
  // cout << "\033c";
  for (int i = 0; i < professorTypeSIZE; i++)
  {
    professor[0]->print(0);
  }
  cout << "select professor #: ";
  cin >> answer;
  cout << endl;
  if (answer >= 0 && answer < professorTypeSIZE)
  {
    cout << "you have selected professor #: " << answer << endl;
    cout << "Now select a course - > - > - >" << endl;
    for (int i = 0; i < courseTypeSIZE; i++)
    {
      courses[i]->print(courses, courseTypeSIZE, i);
    }
    cout << "Select course #: ";
    cin >> courseAnswer;
    cout << endl;
    if (courseAnswer >= 0 && courseAnswer < courseTypeSIZE)
    {
      professor[answer]->assignCourse(courses, courseAnswer, courseTypeSIZE);
    }
    else
    {
      cout << "error try a different number";
      system("pause");
      return;
    }
  }
  else
  {
    cout << "error try a different number";
    system("pause");
    return;
  }
  system("pause");
}

void polycallPrint(courseType **& courses, studentType **&student, professorType **&professor, int& studentTypeSIZE, int& professorTypeSIZE, int& courseTypeSIZE){



vector<int> tempNumCourses(studentTypeSIZE);
  int size;
  for(int i = 0; i < studentTypeSIZE; i++) {
    student[i]->print(i);
    student[i]->printother(i);
    tempNumCourses[i] = student[i]->getNumCourses();
    size = tempNumCourses[i];
    size -= 1;
    for(int j = 0; j < size; j++) {
        student[i]->studentCourses[j]->print(courses, courseTypeSIZE, i);
    }
}

system("pause");
}

int main()
{
  // create another set of variables for increase...............
  int sin;
  const int sizeofcourses = 0;
  int studentTypeSIZE = 0;
  int personTypeSIZE = 0;
  int professorTypeSIZE = 0;
  int courseTypeSIZE = 0;
  const int oneStudentTypeSIZE = 50;
  const int onePersonTypeSIZE = 50;
  const int oneProfessorTypeSIZE = 50;
  const int oneCourseTypeSIZE = 50;
  int choice = 0;
  const int totalPersonCount = studentTypeSIZE + personTypeSIZE + professorTypeSIZE;
  courseType **courses = new courseType*[oneCourseTypeSIZE];
  studentType **student = new studentType*[oneStudentTypeSIZE];
  personType **person = new personType*[onePersonTypeSIZE];
  professorType **professor = new professorType*[oneProfessorTypeSIZE];




  do
  {
    cout << "\033c";
    cout << endl
         << endl;
         //cout << professor[0]->getfName();
    // cout << courseType::getCensus();
    cout << "Number of courses: " << courseTypeSIZE << endl;
    cout << "Number of People: " << totalPersonCount << endl;
    cout << "---personType Count: " << personTypeSIZE << endl;
    cout << "---professorType Count: " << professorTypeSIZE << endl;
    cout << "---studentType Count: " << studentTypeSIZE << endl;
    cout << "----------------------------------------------" << endl;
    cout << "<1> Create NEW Course" << endl;
    cout << "<2> Create NEW Person" << endl;
    cout << "<3> Enroll Student" << endl;
    cout << "<4> Assign Instructor" << endl;
    cout << "<5> Print All People" << endl;
    cout << "<6> Print All Courses" << endl;
    cout << "<7> Print Census" << endl;
    cout << "<8> Exit" << endl;
    cout << "Choice: ";
    cin >> choice;
    cin.clear();
    cin.ignore();
    switch (choice)
    {
    case 0:
      cout << "\033c";
      break;
    case 1:
      cout << "\033c";
      addCourses(courses, courseTypeSIZE);
      break;
    case 2:
      createPerson(person, student, professor, studentTypeSIZE, professorTypeSIZE, personTypeSIZE);
      break;
    case 3:
      enrollStudent(student, courses, studentTypeSIZE, courseTypeSIZE);
      break;
    case 4:
      assignProfessor(professor, courses, professorTypeSIZE, courseTypeSIZE);
      break;
    case 5:
    polycallPrint(courses, student, professor, studentTypeSIZE, professorTypeSIZE, courseTypeSIZE);
      break;
    case 6:
      for (int i = 0; i < courseTypeSIZE; i++)
      {
        courses[i]->print(courses, courseTypeSIZE, i);
      }
      system("pause");
      break;
    case 7:
    cout << "\033c";
      cout << "*     Saddleback College 2023 CENSUS     " << endl;
      cout << "* " << courseType::getCensus();
      system("pause");
      break;
    case 8:
      break;
    default:
      cout << "\033c";
      cout << "Exiting" << endl;
      break;
    }
  } while (choice != 8);
}

/*cout << "\033c";
      for(int i = 0; i < personElements; i++){
        person->print(person, i);
      }
      for(int i = 0; i < studentElements; i++){
        studentPerson->print(studentPerson, i);
      }
       for(int i = 0; i < professorElements; i++){
        professorPerson->print(professorPerson, i);
      }
      cin >> sin;*/