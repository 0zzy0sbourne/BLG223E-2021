#include <bits/stdc++.h>

using namespace std; 

struct ListNode{
    int val; 
    ListNode* next; 
    ListNode(int x) {val=x;}
};




int main()
{
    ListNode* head = new ListNode(1) ;
    head->next = new ListNode(4);  
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = nullptr; 

    ListNode* p1 = head;
    ListNode* p2 = head; 

    while ( p2->next != nullptr ) 
    {
        p2 = p2->next;
        if (p2->next != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    
}