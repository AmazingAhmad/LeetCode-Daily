#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& time, int targetFriend) {
        int tarArr = time[targetFriend][0], n = time.size();
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        set<int> s;
        sort(time.begin(), time.end());
        int maxSeat = 0, seat;
        
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && pq.top()[0] <= time[i][0])
            {
                s.insert(pq.top()[1]);
                pq.pop();
            }
            if(!s.empty())
            {
                seat = *s.begin();
                s.erase(s.begin());
            }
            else
                seat = maxSeat++;

            if(time[i][0] == tarArr)
                return seat;
            pq.push({time[i][1], seat});
        }
        return -1;
    }
};