/* @Author
Student Name: Ozan Çetin
Student ID : 150190021
Date: 01.11.2021 */
#include <iostream>
#include <stdio.h>

#include "linkedList.h"

using namespace std;
int LinkedList::initializeList(char* filename){
    FILE* fileptr; 
    fileptr = fopen(filename, "r");
    
    fseek(fileptr, 0L, SEEK_END); // seek end of the file
    size_t size = ftell(fileptr); // ask for the size
    fseek(fileptr, 0L, SEEK_SET); // and then seek back
    int length =( size / 2 ) + 1 ;
    
    char c = fgetc(fileptr);
    int nodeCounter = 1;
    // Node* traverse = this->head;
    while(!feof(fileptr)){
        if(c != '\n')
        {
            // cout << c;
            Node* newNode = new Node(); 
            newNode->letter = c; 
            if(nodeCounter == 1) // then it is head
            {
                this->head = newNode;
                this->head->next = nullptr;
            }
            /*
            else if (nodeCounter == length) // then it is tail
            {
                this->tail = newNode;
                this->tail->next = head;
            }
            */
            else {
                newNode->next = nullptr;
                Node* traverse = this->head;
                while(traverse->next != nullptr){
                    traverse = traverse->next;
                }
                traverse->next = newNode;
                if(nodeCounter == length){
                    this->tail = traverse->next;
                    this->tail->next = head;
                }

            } 
            nodeCounter++;
        }
        c = fgetc(fileptr);
    }
    /* 
    nodeCounter = 1 ;
    Node* current = head; 
    while(nodeCounter <= length){
        cout << current->letter << " " ; 
        current = current->next;
        if(current == head) break;
        nodeCounter++;
    }
    */
    
    // cout << head->next->letter; 
    fclose(fileptr);
    return 0; 
};


void LinkedList::reorderList(){
    //FILL THIS FUNCTION ACCORDINGLY
    Node *current = head, *index = nullptr;  
    int temp;  
    if(head == nullptr)
    {  
        printf("List is empty");  
    }  
    else {  
        do{  
            index = current->next;  
            while(index != head) {  
            if(current->letter > index->letter) {  
                temp =current->letter;  
                current->letter= index->letter;  
                index->letter = temp;  
            }  
            index= index->next;  
        }  
        current =current->next;  
        }while(current->next != head);   
    }  
};

void LinkedList::removeDublicates(){
    //FILL THIS FUNCTION ACCORDINGLY
    //Current will point to head  
    Node *current = head, *index = nullptr, *temp = nullptr;  
    if(head == nullptr) 
    {  
        printf("List is empty");  
    }  
    else {  
        do{  
        //Temp will point to previous node of index.  
        temp = current;  
        //Index will point to node next to current  
        index = current->next;  
        while(index != head) 
        {  
            //If current node is equal to index data  
            if(current->letter == index->letter) 
            {  
            //Here, index node is pointing to the node which is duplicate of current node  
            //Skips the duplicate node by pointing to next node  
            temp->next = index->next;  
            }  
            else
            {  
                //Temp will point to previous node of index.  
                temp = index;  
            }  
            index= index->next;  
        }  
        current =current->next;  
}while(current->next != head);   
}  
};

void LinkedList::reverseList(){
    //FILL THIS FUNCTION ACCORDINGLY
    // Temporary helper variables
    Node *prev, *cur, *last;

    // Cannot reverse empty list
    if (head == nullptr)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }


    last = head;

    prev  = head;
    cur   = (head)->next;
    head = (head)->next;

    // Iterate till you reach the initial node in circular list
    while (head != last)
    {
        head = (head)->next;
        cur->next = prev;

        prev = cur;
        cur  = head;
    }

    cur->next = prev;
    head = prev;       // Make last node as head
};

void LinkedList::printList(){
    Node* temp = head;
    while(true){
        cout<<temp->letter<<" ";
        temp = temp->next;
        if(temp == head)
            break;
    }
    cout<<endl;
};