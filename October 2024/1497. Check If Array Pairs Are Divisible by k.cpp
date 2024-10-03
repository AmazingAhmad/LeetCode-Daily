#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        int um[k];
        for(int i=0;i<k;i++)
            um[i] = 0;

        for(int i=0;i<n;i++)
        {
            int mod = ((arr[i] % k) + k) % k;
            um[mod]++;
        }
        if(um[0] % 2)
            return false;
        for(int i=1;i<=k/2;i++)
            if(um[i] != um[k-i])
                return false;
        return true;
    }
};