#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

using namespace std; 
  struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) { val = x; }
  }; 

void deletedups(ListNode*);

int main()
{ 

    ListNode* head = new ListNode(1) ;
    head->next = new ListNode(4);  
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = nullptr; 

    deletedups(head);

    // print the list
    ListNode* current = head; 
    while(current)
    {
        cout << current->val << " ";
        current = current->next;
    }
}

void deletedups(ListNode* head)
{
    unordered_set<int> set ; 
    ListNode* previous = nullptr; 
    ListNode* current = head; 
    while(current != nullptr)
    {
        auto search = set.find(current->val) ;
        if(search == set.end()) // set does not  contains the value
        {   
            set.insert(current->val); 
            previous = current; 
        }
        else { // set contains the value 
            previous->next = current->next;
        }
        current = previous->next; 
    }
     
}