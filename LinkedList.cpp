//A program to create and manage a linked list
//Created by: Ethan Reese
//Date: November 29, 2017

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Student* newStudent, Node* &head);
void print(Node* next);
void deleteStudent(char* studentName, Node* head);
void toLowerCase(char (&arr)[80]);

int main(){
     //Fix the head of the linked list
     Node* head = NULL;
     //Run a while loop that can 
     while(true){
          cout << "Your command words are 'Add', 'Delete', and 'Print'";
          char input[80];
          cin >> input;
          toLowerCase(input);
          //If they want to add a student to the list
          if(strcmp(input, "add") == 0){
               cout << "Please enter the name of the student";
               char nameInput[80];
               cin >> nameInput;
               toLowerCase(nameInput);
               char* nameInputNew = new char[80];
               strcpy(nameInputNew, nameInput);
               Student* student = new Student(nameInputNew);
               delete [] nameInputNew;
               add(student, head);
          }
          //If they want to delete a character
          else if(strcmp(input, "delete") == 0){
               cout << "Enter the name of the student you would like to delete";
               char nameInput[80];
               cin >> nameInput;
               toLowerCase(nameInput);
               char* nameInputNew = new char[80];
               strcpy(nameInputNew, nameInput);
               deleteStudent(nameInput, head);
               delete [] nameInputNew;
          }
          //If they want to print out all of the students
          else if(strcmp(input, "print") == 0){
               print(head);
          }
     }          

}

//Function that takes an array and makes all the characters lowercase
void toLowerCase(char (&arr)[80]){
     //Loop through the character array and make every item lowercase
     for(int i = 0; i < 80; i++){
          arr[i] = tolower(arr[i]);
     }
}
//Function that can add a node to the linked list
void add(Student* newStudent, Node* &head){
     Node* current = head;
     //If its the first node in the chain then it can just be created in isolation
     if(current == NULL){
          head = new Node(newStudent);
     }
     //Otherwise it needs to go through the whole chain and figure it out
     else{
             //Goes through the list until it finds an empty space
             while(current->getNext() != NULL){
               current = current->getNext();
             }
             current -> setNext(new Node(newStudent));
     }
}
//Function that prints out every node
void print(Node* next){
     //If there is something in this node
     if(next != NULL){
          next->getStudent()->printName();
          cout << endl;
          print(next->getNext());
     }
}
//Function that can delete an item of the linked list given a name input
void deleteStudent(char* studentName, Node* head){
     Node* current = head;
     //Loop over all the nodes and find one with a matching name
     while(current->getNext() != NULL){
          if(strcmp(current->getNext()->getStudent()->getName(), studentName) == 0){
               Node* newNext = current->getNext()->getNext();
               delete current->getNext();
               current->setNext(newNext);
               return;
          }
          current = current->getNext();
     }
     cout << "That name wasn't in the linked list";
}
