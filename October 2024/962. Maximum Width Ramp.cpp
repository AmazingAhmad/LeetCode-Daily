#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> maxRight(n);
        maxRight[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            maxRight[i] = max(maxRight[i+1], nums[i]);
        
        int left = 0, right = 0;
        while(right < n)
        {
            while(left < right && nums[left] > maxRight[right])
                left++;
            res = max(right-left, res);
            right++;
        }

        return res;
    }
};