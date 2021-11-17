#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std; 
  struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) { val = x; }
  }; 

ListNode* Partition(ListNode*, int); 

int main()
{ 
    
    ListNode* head = new ListNode(1) ;
    head->next = new ListNode(4);  
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = nullptr; 
    ListNode* newlisthead = Partition(head, 3);
    while(newlisthead != nullptr) 
    {
        cout<<newlisthead->val << " " ; 
        newlisthead = newlisthead->next;
    } 
    /*
    string name = "ozan"; 
    string name2 = "cetin"; 
    char onechar = name2[0];  
    name.push_back(onechar); 
    cout << name << endl; 
    */ 
}

ListNode* Partition(ListNode* head, int x)
{
    ListNode* lowerHead = nullptr; 
    ListNode* lowerTail = nullptr;              //Head and Tail of lower list
    ListNode* greaterHead = nullptr;
    ListNode* greaterTail = nullptr;          //Head and Tail of greater list

    ListNode *current = head;

    while (current != nullptr)
    {
        if (current->val < x)
        {
            if (lowerHead == nullptr) lowerHead = current;      //If is the first node in the list
            if (lowerTail == nullptr) lowerTail = current;      //set the head an tail to the same value
            else lowerTail = lowerTail->next = current;       //Otherwise, add the node and update the tail
        }
        else
        {
            if (greaterHead == nullptr) greaterHead = current;  //If is the first node in the list
            if (greaterTail == nullptr) greaterTail = current;  //set the head an tail to the same value
            else greaterTail = greaterTail->next = current;   //Otherwise, add the node and update the tail
        }

        current = current->next;
    }

    if (greaterHead != nullptr)
        greaterTail->next = nullptr;

    if (lowerHead == nullptr) return greaterHead;
    else
    {
        lowerTail->next = greaterHead;
        return lowerHead;
    }
} 