#ifndef PERSONTYPE_H
#define PERSONTYPE_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

class personType
{
private:
    string fName;
    string lName;
    string address;
    double height; // inches
    string DOB;
    char gender;
    // constructor

public:
    personType();
    personType(string fName, string lName);
    personType(string fName, string lName, string address, string DOB, double height, char gender);
    ~personType();

    // get functions
    string getfName();
    string getlName();
    string getAddress();
    double getHeight();
    string getDOB();
    char getGender();
    // set functions
    void setfName(string fname);
    void setlName(string iname);
    void setAddress(string Address);
    void setHeight(double Height);
    void setDOB(string dob);
    void setGender(char Gender);
    // print and equals
    virtual void print(personType person[], int value);
    bool equals(personType person[], personType personTwo[], const int SIZE);
    
    // finds whether or not if theres duplicate in a class object
    void duplicateSearch(personType person[], const int SIZE);

    void enterInfo(personType person[], const int SIZE);
};


#endif