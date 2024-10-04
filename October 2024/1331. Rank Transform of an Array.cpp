#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        int n = arr.size(), cur=1;
        vector<int> temp, res;
        if(n == 0)
            return res;
        if(n == 1)
            return {1};
        temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> um;
        um[temp[0]] = cur;

        for(int i=1;i<n;i++)
        {
            if(temp[i] != temp[i-1])
                um[temp[i]] = ++cur;
        }

        for(int i=0;i<n;i++)
            res.push_back(um[arr[i]]);
        return res;
    }
};