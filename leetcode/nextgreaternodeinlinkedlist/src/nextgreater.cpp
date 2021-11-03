#include <iostream> 
#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

int main(){
    vector<int> ans ;
        // create the linked list
        ListNode* head = new ListNode(2); 
        head->next = new ListNode(1);
        head->next->next = new ListNode(5);

    ListNode* current = head ; 
    while(current != nullptr)
    {
        bool found = false;
        ListNode* traverse = current; 
        while(traverse != nullptr && !found)
        {
            if(current->val < traverse->val)
            {
                ans.push_back(traverse->val);
                found = true;
            }     
            traverse = traverse->next;
        }
        if(!found) ans.push_back(0); 
        current = current->next;
    }
    for(auto & element : ans){
        cout << element << endl;
    }
    return 0;
}
