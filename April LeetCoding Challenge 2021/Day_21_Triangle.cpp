class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=i; j++)
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
        
        return dp[0][0];
    }
};
