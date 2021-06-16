class Solution {
public:
    vector<string> ans;
    
    void paren(string s, int open, int n){
        if(n == 0){
            while(open--)
                s += ')';
            ans.push_back(s);
            return;
        }
        if(open > 0)
            paren(s + ')', open-1, n);
        paren(s + '(', open+1, n-1);
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        paren(s + '(', 1, n-1);
        return ans;
    }
};
