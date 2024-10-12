#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        int n = s.length(), res=n;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'A' || s[i] == 'C')
                st.push(s[i]);
            else if(!st.empty() && (s[i] == 'B' && st.top() == 'A'
                    || s[i] == 'D' && st.top()  == 'C'))
            {
                st.pop();
                res -= 2;
            }
            else
                while(!st.empty())
                    st.pop();
        }
        return res;
    }
};