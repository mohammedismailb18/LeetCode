class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        unordered_set<int> s(nums.begin(), nums.end());
        int len,j, ans = 1;
    
        for(auto num : s){
            if(s.find(num-1) != s.end())
                continue;
            j = 1;
            while(s.find(num+j) != s.end()) j++;
            ans = max(ans, j);
        }
        return ans;
    }
};
