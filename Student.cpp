#include "Student.h"
#include <cstdlib>
#include <cstring>
#include <iostream>


using namespace std;


Student::Student(char* newName){
     //Assign all of the nessecary variables here
     name = new char[80];
     strcpy(name, newName);
}

Student::~Student(){
     //Deconstructor class. There is nothing in it yet to destruct.
     delete name;
}
void Student::printName(){
     cout << name;
}
char* Student::getName(){
     return name;
}
