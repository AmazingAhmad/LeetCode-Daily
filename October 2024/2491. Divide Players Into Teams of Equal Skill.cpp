#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill)
    {
        int n = skill.size();
        int map[1001] = {0}, maxi = -1, mini = 1001;
        for(int i=0;i<n;i++)
        {
            map[skill[i]]++;
            maxi = max(maxi, skill[i]);
            mini = min(mini, skill[i]);
        }
        int tar = maxi + mini;
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            if(!map[skill[i]])
                continue;
            if(map[tar - skill[i]])
            {
                res = res + (skill[i] * (tar - skill[i]));
                map[tar - skill[i]]--;
                map[skill[i]]--;
            }
            else
                return -1;
        }
        return res;
    }
};