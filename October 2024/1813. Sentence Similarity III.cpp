#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int state = 0;
        if(s1.length() > s2.length())
            swap(s1, s2);
        stringstream ss1(s1), ss2(s2);
        string s;
        vector<string> a1, a2;
        while(getline(ss1, s, ' '))
            a1.push_back(s);

        while(getline(ss2, s, ' '))
            a2.push_back(s);

        int st = 0, en1 = a1.size() - 1, en2 = a2.size() - 1;
        while(st <= en1 && a1[st] == a2[st])
            st++;
        while(en1 >= 0 && a1[en1] == a2[en2])
        {
            en1--;
            en2--;
        }
        return en1 < st;
    }
};