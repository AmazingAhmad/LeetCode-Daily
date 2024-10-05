#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        unordered_map<char, int> um;
        for(int i=0;i<m;i++)
            um[s1[i]]++;
        int cur = 0, st=0, en=0;
        for(int i=0;i<n;i++)
        {
            if(um[s2[i]])
            {
                en++;
                um[s2[i]]--;
                cur++;
            }
            else
            {
                while(s2[st] != s2[i])
                {
                    um[s2[st]]++;
                    st++;
                    cur--;
                }
                st++;
                en++;
            }
            if(cur == m)
                return true;
        }
        return false;
    }
};