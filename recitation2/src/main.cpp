/* @Author
Student Name: Ozan Çetin
Student ID : 150190021
Date: 01.11.2021 */
#include <iostream> 
#include <stdlib.h>
#include <fstream>

#include "linkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
	// system("clear");// make this line as comment if you are compiling on Linux or Mac
	//system("cls"); // make this line as comment if you are compiling on Windows

    LinkedList* newLinkedList = new LinkedList();
    char* filename = argv[1];

    newLinkedList->initializeList(filename);
    /* 
    newLinkedList->printList();    // WORKS 
    newLinkedList->reorderList();
    newLinkedList->printList();
    newLinkedList->removeDublicates();
    newLinkedList->printList();
    newLinkedList->reverseList(); 
    newLinkedList->printList();
    */ 


    
    
    
    cout<<"Readed letters in Circular Linked List: ";
    newLinkedList->printList();

    newLinkedList->reorderList();
    cout<<"After reordering: ";
    newLinkedList->printList();

    newLinkedList->removeDublicates();
    cout<<"After removing dublicates: ";
    newLinkedList->printList();
    
    newLinkedList->reverseList();
    cout<<"Reversed Circular list: ";
    newLinkedList->printList();

    return EXIT_SUCCESS;
}