class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), lcount = 0,rcount = 0;
        for(int i=0;i<n/2;i++){
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' ||
               s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
                lcount++;
        }
        for(int i=n/2;i<n;i++){
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' ||
               s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
                rcount++;
        }
        if(lcount == rcount)
            return true;
        else
            return false;
    }
};
