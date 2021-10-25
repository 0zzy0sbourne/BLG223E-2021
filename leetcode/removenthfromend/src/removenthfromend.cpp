#include <iostream> 
#include <map>

using namespace std;
  // use map 

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
int main(){
    int n = 2 ; 

    ListNode* head = new ListNode(1); 
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // sample linked list is created. 
    
    // print the linked list: 
    ListNode* current = head; 
    while(current!=nullptr){
        cout << current->val << " " ;  
        current = current->next; 
    } cout << "\n"; 



    // TODO: define a map
    map<int, ListNode*> nodemap; 
    int size = 0; 
    ListNode* traverse = head; 
    
    while(traverse != nullptr){
        nodemap.insert({size+1, traverse}); 
        size++;
        traverse = traverse->next;
    }

    int x = size - (n-1); // index of the node we search

    if(x == 1){
        head = nodemap[x]->next; 
        delete nodemap[x];
    } else if(x == size){
        // cut the link between the last elem and the one before that
        nodemap[x-1]->next = nullptr;
        delete nodemap[x]; 

    } else{
        nodemap[x-1]->next = nodemap[x]->next; 
        delete nodemap[x];
    }

    current = head; 
    while(current!=nullptr){
        cout << current->val << " " ;  
        current = current->next; 
    }





//     cout << head->next->next->val <<endl  ; 


    return 0; 
}