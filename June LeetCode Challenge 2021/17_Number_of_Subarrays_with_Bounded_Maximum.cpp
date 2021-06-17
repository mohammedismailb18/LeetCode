class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, dp = 0, prev = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < left)
                ans += dp;
            else if(nums[i] > right)
                dp = 0, prev = i;
            else
                dp = i - prev, ans += dp;
        }
        return ans;
    }
};
