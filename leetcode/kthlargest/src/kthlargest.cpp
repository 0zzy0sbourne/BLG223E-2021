#include <bits/stdc++.h>
using namespace std; 

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> pq; 
    int p; 
    
    KthLargest(int k, vector<int>& nums) {
     p = k; 
        for (auto i:nums)
        {
            add(i);  
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > p)
        {
            pq.pop(); 
        }
        return pq.top(); 
        
    }
};
