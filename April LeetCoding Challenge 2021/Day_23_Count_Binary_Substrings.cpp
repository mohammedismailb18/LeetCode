class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0, prev = 0, current = 1, sum = 0;
        while(s[i]){
            if(s[i+1] && s[i]!=s[i+1]){
                sum += min(current, prev);
                prev = current;
                current = 1;
            }
            else
                current++;
            i++;
        }
        return sum += min(current-1,prev);
    }
};
