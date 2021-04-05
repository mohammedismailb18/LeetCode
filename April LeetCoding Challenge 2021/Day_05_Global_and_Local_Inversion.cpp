class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int greater = 0, n = A.size();
        for(int i=0; i<n-2; i++){
            greater = max(greater, A[i]);
            if(greater > A[i+2])
                return false;
        }
        return true;
    }
};
