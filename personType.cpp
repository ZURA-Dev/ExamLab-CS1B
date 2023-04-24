#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "personType.h"

using namespace std;

personType::personType(){};
personType::personType(string fName, string lName)
{this->fName = fName; this->lName = lName;};
personType::personType(string fName, string lName, string address, string DOB, double height, char gender)
{
    this->fName = fName;
    this->lName = lName;
    this->address = address;
    this->height = height;
    this->DOB = DOB;
    this->gender = gender;
};
personType::~personType(){};

// get functions
string personType::getfName() { return fName; }
string personType::getlName() { return lName; }
string personType::getAddress() { return address; }
double personType::getHeight() { return height; }
string personType::getDOB() { return DOB; }
char personType::getGender() { return gender; }
// set functions
void personType::setfName(string fname) { this->fName = fname; }
void personType::setlName(string iname) { this->lName = iname; }
void personType::setAddress(string Address) { this->address = Address; }
void personType::setHeight(double Height) { this->height = Height; }
void personType::setDOB(string dob) { this->DOB = dob; }
void personType::setGender(char Gender) { this->gender = Gender; }
// print and equals
void personType::print(personType person[], int value)
{

    cout << endl;
    cout << "personType Print:" << endl;
    cout << "Printing Person # " << value << ": " << setw(10) << "--------------" << endl
         << endl;
    cout << "First Name: " << person[value].getfName() << endl;
    cout << "Last Name: " << person[value].getlName() << endl;
    cout << "Address: " << person[value].getAddress() << endl;
    cout << "Height: " << person[value].getHeight() << endl;
    cout << "Gender: " << person[value].getGender() << endl;
    cout << "Date of Birth: " << person[value].getDOB() << endl;
}
bool personType::equals(personType person[], personType personTwo[], const int SIZE)
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
// finds whether or not if theres duplicate in a class object
void personType::duplicateSearch(personType person[], const int SIZE)
{
    // vectors to store values
    vector<int> matchOne;
    vector<int> matchTwo;
    vector<int> noMatchTwo;
    vector<int> noMatchOne;
    // if match put into array
    for (int j = 0; j < SIZE; j++)
    {

        for (int i = 0; i < SIZE; i++)
        {
            if (i != j && person[j].getfName() == person[i].getfName() && person[j].getlName() == person[i].getlName() && person[j].getAddress() == person[i].getAddress() && person[j].getHeight() == person[i].getHeight() && person[j].getDOB() == person[i].getDOB() && person[j].getGender() == person[i].getGender())
            {
                matchOne.push_back(j);
                matchTwo.push_back(i);
            }
            else
            {
                noMatchOne.push_back(j);
                noMatchTwo.push_back(i);
            }
        }
    }
    // remove dupe from second array
    /*
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (j != i && matchOne[j] == matchTwo[i])
            {
                matchOne.erase(find(matchOne.begin(), matchOne.end(), j));
            }
        }
    }
    // remove dupe from first array
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (j != i && matchTwo[j] == matchOne[i])
            {
                matchTwo.erase(find(matchTwo.begin(), matchTwo.end(), j));
            }
        }
    }
    */
    for (int i = 0; i < matchTwo.size(); i++)
    {
        cout << "duplicates found" << endl;
        cout << "position: " << i << ": ";
        cout << matchOne[i] << " " << person[matchOne[i]].getfName() << endl;
    }
    cout << "No Dupes Found" << endl;
    system("pause");

    /*for (int i = 0; i < pos; i++)
    {
        if (person[matchOne[i]].getfName() == person[matchTwo[i]].getfName())
        {
            cout << "Match:" << endl
                 << endl;
            cout << person[matchOne[i]].getfName() << endl;
            cout << person[matchTwo[i]].getfName() << endl;
        }
    }
    for (int i = 0; i < noMatchTwo[pos]; i++)
    {
        // cout << "No Match:" << endl << endl;
        // cout << person[noMatchOne[i]].getfName() << endl;
        // cout << person[noMatchTwo[i]].getfName() << endl;
    }
    system("pause"); */
}

void personType::enterInfo(personType person[], const int SIZE)

{
    string fname;
    string lname;
    string address;
    double height; // inches
    string DOB;
    char gender;
    int choice;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\033c";
        cout << "entering info in person position: " << i << setw(40) << "Database Size: " << SIZE << endl;
        cout << "enter first name: " << endl;
        cin >> fname;
        cout << "enter last name: " << endl;
        cin >> lname;
        cout << "enter address: " << endl;
        getline(cin, address);
        system("pause");
        cout << "enter height (inches): " << endl;
        cin >> height;
        cout << "enter DOB: " << endl;
        cin >> DOB;
        cout << "enter gender: " << endl;
        cin >> gender;

        person[i].setfName(fname);
        person[i].setlName(lname);
        person[i].setAddress(address);
        person[i].setHeight(height);
        person[i].setDOB(DOB);
        person[i].setGender(gender);
        if (i != SIZE - 1)
        {
            cout << "would you like to continue entering?" << endl;
            cout << "1. continue" << endl;
            cout << "2. Exit" << endl;
            cout << "Enter: ";
            cin >> choice;
            cin.clear();
            cin.ignore();
            if (choice == 2)
            {
                return;
            }
        }
    }
}
