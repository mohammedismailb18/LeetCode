class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        result.push_back({1});
        if(n >= 2)
            result.push_back({1,1});
        for(int i=3; i<=n; i++){
            vector<int> ans;
            ans.push_back(1);
            vector<int> prev = result.back();
            for(int j=1; j<prev.size(); j++)
                ans.push_back(prev[j] + prev[j-1]);
            ans.push_back(1);
            result.push_back(ans);
        }
        return result;
    }
};
