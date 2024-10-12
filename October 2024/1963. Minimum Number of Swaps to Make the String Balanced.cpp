#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
       int n = s.length(), open=0, res=0;
       for(int i=0;i<n;i++)
       {
            if(s[i] == '[')
                open++;
            else
            {
                if(open)
                    open--;
                else
                {
                    open++;
                    res++;
                }
            }
       }
        return res;
    }
};