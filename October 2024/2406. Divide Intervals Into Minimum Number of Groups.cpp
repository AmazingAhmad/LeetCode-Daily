#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& times)
    {
        sort(times.begin(), times.end());
        int n = times.size(), res = 1, cur = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(times[0][1]);
        for(int i=1;i<n;i++)
        {
            while(!pq.empty() && times[i][0] > pq.top())
            {
                pq.pop();
                cur--;
            }
            pq.push(times[i][1]);
            cur++;
            res = max(res, cur);
        }
        return res;
    }
};