/* @Author
Student Name: Ozan Çetin
Student ID : 150190021
Date: 01.11.2021 */
#ifndef _H
#define _H

#include <iostream>
#include <stdio.h>

using namespace std;

class Node{
    public:
        char letter;
        Node* next;
};


class LinkedList{

    Node* head;
    Node* tail;

    public:
        int initializeList(char*);
        void reorderList();
        void removeDublicates();
        void reverseList();
        void printList();
};

#endif