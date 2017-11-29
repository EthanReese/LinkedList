#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
     public:
          //Main functions
          Node(Student*);
          ~Node();
          void setNext(Node*);
          Student* getStudent();
          Node* getNext();
     private:
          Node* next;
          Student* student;
};
#endif
