class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> num;
        int l=1,r=k+1;
        while(l<=r){
            num.push_back(l++);
            if(l<=r)
                num.push_back(r--);
        }
        for(int i=k+2; i<=n; i++)
            num.push_back(i);
        return num;
    }
};
