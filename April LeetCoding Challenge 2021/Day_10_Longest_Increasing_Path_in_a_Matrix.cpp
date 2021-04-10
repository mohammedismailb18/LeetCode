
class Solution {
public:
    int dp[201][201];
    
    int dfs(vector<vector<int>>& matrix, int x, int y, int prev){
        if(x<0 || y<0 || x==matrix.size() || y==matrix[0].size() || prev>=matrix[x][y])
            return 0;
        if(dp[x][y])
            return dp[x][y];
        
        int value = matrix[x][y];
        matrix[x][y] = -1;
        int l = dfs(matrix, x, y-1, value);
        int u = dfs(matrix, x-1, y, value);
        int r = dfs(matrix, x, y+1, value);
        int d = dfs(matrix, x+1, y, value);
        matrix[x][y] = value;
        return dp[x][y] = 1 + max({l,u,r,d});
    }    
        
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(), max_len = -1;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                max_len = max(max_len, dfs(matrix, i, j, -1));
        return max_len;
    }
};
