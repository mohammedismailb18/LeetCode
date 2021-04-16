#include<bits/stdc++.h>

class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        
        for(int i=s.size() - 1; i>=0; i--){
            if(!stk.empty() && s[i] == stk.top().first){
                stk.top().second++;
                if(stk.top().second == k)
                    stk.pop();
            }
            else
                stk.push({s[i],1});
        }
        
        int count;
        string res;
        while(!stk.empty()){
            count = stk.top().second;
            while(count--)
                res += stk.top().first;
            stk.pop();
        }
        return res;
    }
};
