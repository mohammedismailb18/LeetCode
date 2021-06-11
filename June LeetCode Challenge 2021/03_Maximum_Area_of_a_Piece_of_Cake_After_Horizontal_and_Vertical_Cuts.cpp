class Solution {
public:
    long long mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = horizontalCuts[0], maxW = verticalCuts[0], mod = 1e9 + 7;
        for(int i=1; i<horizontalCuts.size(); i++)
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        for(int i=1; i<verticalCuts.size(); i++)
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i-1]);
        maxH = max(maxH, h - horizontalCuts.back());
        maxW = max(maxW, w - verticalCuts.back());
        return ((long)(maxH % mod)*(maxW % mod)%mod);
    }
};
