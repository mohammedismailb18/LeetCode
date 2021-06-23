class Solution {
public:

    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0, m = s.length(), n, i, j;
        unordered_map<string, bool> isSub;
        for(auto& word : words){
            if(isSub.find(word) != isSub.end()){
                if(isSub[word])
                    count++;
                continue;
            }
            n = word.length(), j = 0, i = 0;
            while(i<m && j<n){
                if(s[i] == word[j])
                    i++, j++;
                else
                    i++;
            }
            if(j == n){
                count++;
                isSub[word] = true;
            }
            else
                isSub[word] = false;
        }
        return count;
    }
};
