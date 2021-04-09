/*
The idea is to simply compare the adjacent words are in sorted order. if they are in ordered,
then compare next adjacent pair. If we found any pair in not order, then return false 
else continue the process for remaining words. If we are able to loop through all the words,
then it means the given words are in lexicographically sorted order.
*/

class Solution {
public:
    
    int rank[26];
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<26; i++)
            rank[order[i] - 'a'] = i;
        for(int i=0; i<words.size()-1; i++){
            if(!compare(words[i], words[i+1]))
                return false;
        }
        return true;
    }
    
 	//compare function return false if a is lexicographically larger than b else return true
    bool compare(string a, string b){
        int n1 = a.size(), n2 = b.size();
        int m = min(n1,n2);
        for(int i=0; i<m; i++){
            if(rank[a[i] - 'a'] < rank[b[i] - 'a'])
                return true;
            else if(rank[a[i] - 'a'] > rank[b[i] - 'a'])
                return false;
        }
        return n2>=n1;
    }
};
