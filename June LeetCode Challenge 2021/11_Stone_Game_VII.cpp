class Solution {
public:
    int dp[1001][1001];
    int helper(vector<int>& stones, int l, int r, int sum){
        if(l == r)
            return 0;
        if(dp[l][r] != -1)  return dp[l][r];
        int res1 = sum - stones[l] - helper(stones, l+1, r, sum - stones[l]);
        int res2 = sum - stones[r] - helper(stones, l, r-1, sum - stones[r]);
        dp[l][r] = max(res1, res2);
        return dp[l][r];
    }
    
    
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(stones.begin(), stones.end(), 0);
        return helper(stones, 0, stones.size()-1, sum);
    }
};
