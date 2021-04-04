class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), sum = 0, maxim = 0, index, last;
        stack<int> p;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                p.push(i);
            else if(s[i] == ')'){
                if(!p.empty() && s[p.top()] == '('){
                    p.pop();
                }
                else
                    p.push(i);
            }
        }
        
        if(p.empty())
            return n;
        
        index = p.top();
        p.pop();
        maxim = max(maxim, n-index-1);
        last = index;
        
        while(!p.empty()){
            index = p.top();
            p.pop();
            maxim = max(maxim, last - index - 1);
            last = index;
        }
        
        maxim = max(maxim, last-0);
        return maxim;
    }
};
