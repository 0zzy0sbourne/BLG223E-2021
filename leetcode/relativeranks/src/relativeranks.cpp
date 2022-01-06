#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>q;
        string ranks[3]= {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(int i=0;i<score.size();i++)
        {
            q.push({score[i], i});
        }
        vector<string> result(size(q));
        int count =0;
        while(!q.empty()){
            result[q.top().second]=count==0?"Gold Medal":count==1?"Silver Medal":count==2?"Bronze Medal":to_string(count+1);
            count++;
            q.pop();
        }
      
        return result;
    }
};
