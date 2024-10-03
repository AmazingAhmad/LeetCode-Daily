#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n = nums.size(), tar = 0;
        unordered_map<int, int> um;
        for(int i=0;i<n;i++)
            tar = (tar + nums[i]) % p;

        if(tar == 0)
            return 0;
        
        int preSum = 0, res = n;
        um[0] = -1;
        for(int i=0;i<n;i++)
        {
            preSum = (preSum + nums[i]) % p;
            int need = (preSum - tar + p) % p;
            if(um.find(need) != um.end())
            {
                cout << i << " " << need << " " << um[need] << endl;
                res = min(res, i - um[need]);
            }
            um[preSum] = i;
        }
        if(res == n)
            return -1;
        return res;
    }
};