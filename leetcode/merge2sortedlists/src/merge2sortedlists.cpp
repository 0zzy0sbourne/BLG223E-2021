#include <iostream> 

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  int main(){

    // create the first linked list
    ListNode* head1 = new ListNode(1); 
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode* current = head1; 
    while(current!=nullptr){
        cout << current->val << " " ;  
        current = current->next; 
    } cout << "\n";
    
    // create the second linked list
    ListNode* head2 = new ListNode(1); 
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    
    current = head2; 
    while(current!=nullptr){
        cout << current->val << " " ;  
        current = current->next; 
    } cout << "\n";
    
    ListNode* mergedhead;
    ListNode* traverse; 
    ListNode* firstptr = head1; 
    ListNode* secptr = head2;  
    
    // mergedhead = (firstptr->val <= secptr->val) ? firstptr : secptr; 
    
    if(firstptr->val <= secptr->val){
        mergedhead = firstptr ; 
        firstptr = firstptr->next; 
    }
    else {
        mergedhead = secptr; 
        secptr = secptr->next;
    }
    
    traverse = mergedhead; 
    
    // keep iterating if at least one of them have still node 
    while(firstptr != nullptr && secptr != nullptr){ 
        if(firstptr->val <= secptr->val ){
            traverse->next = firstptr;
            traverse = traverse->next;   
            firstptr = firstptr->next; 
        }        
        else if(secptr->val < firstptr->val)
        {

            traverse->next = secptr;
            traverse = traverse->next; 
            secptr = secptr->next; 
        }
    }
    if(secptr == nullptr && firstptr != nullptr ){
        traverse->next = firstptr; 
        traverse = traverse->next; 
        firstptr = firstptr->next;
    }
    else if(secptr != nullptr && firstptr == nullptr){
        traverse->next = secptr; 
        traverse = traverse->next; 
        secptr = secptr->next;
    }
    // print the merged linked list
    current = mergedhead; 
    while(current!=nullptr){
        cout << current->val << " " ;  
        current = current->next; 
    } 
    
    return 0; 
  }
 