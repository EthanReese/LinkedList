#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student{
     public:
          Student(char*);
          ~Student();
          void printName();
          char* getName();
     private:
          char* name;
};
#endif
