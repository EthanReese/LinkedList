#include "Node.h"
#include "Student.h"
#include <cstring>
#include <cstdlib>

//Construct the student based on the pointer's input.
Node::Node(Student* newStudent){
     next = NULL;
     student = newStudent;
}

//Delete the elements of the node
Node::~Node(){
     delete student;
}

//Set the next element of the linked list.
void Node::setNext(Node* newNode){
     next = newNode;
}
//Get the student that is at this point on the lsit.
Student* Node::getStudent(){
     return student;
}
//Get the next node in the linked list
Node* Node::getNext(){
     return next;
}
