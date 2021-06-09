class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        priority_queue<pair<int,int>> q;
        dp[n-1] = nums[n-1];
        q.push({dp[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(q.top().second > i+k)
                q.pop();
            dp[i] = nums[i] + q.top().first;
            q.push({dp[i], i});
        }
        return dp[0];
    }
};
