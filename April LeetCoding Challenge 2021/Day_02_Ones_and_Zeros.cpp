class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int items = strs.size(), zeros, ones;
            
        //Table for dynamic programming
        int dp[items+1][m+1][n+1];
        
        for(int i=0; i<=items; i++){
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    
                    if(i == 0 || j==0 && k == 0)
                        dp[i][j][k] = 0;
                    else{
                        zeros = count(strs[i-1].begin(), strs[i-1].end(), '0');
                        ones = strs[i-1].length() - zeros;
                    
                        if(j<zeros || k<ones)         //skip current string
                            dp[i][j][k] = dp[i-1][j][k];
                        else                          //either by skipping or including current string
                            dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][j-zeros][k-ones]);
                    }
                }
            }
        }
        return dp[items][m][n];
    }
};
