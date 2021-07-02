class Solution {
public:
    void helper(vector<int>& result, int n){
        if(n == 0){
            result.push_back(0);
            return;
        }
        helper(result, n-1);
        int mask = 1 << n-1;
        for(int i = result.size() - 1; i>=0; i--)
            result.push_back(result[i] | mask);
    }
    
    vector<int> grayCode(int n) {
        vector<int> result;
        helper(result, n);
        return result;
    }
};
