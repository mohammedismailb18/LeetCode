class Solution {
public:
    void combination(vector<string> letter, int index, string carry, vector<string>& result){
        if(index == letter.size()){
            result.push_back(carry);
            return;
        }
        for(int i=0;i<letter[index].size();i++){
            carry += letter[index][i];
            combination(letter, index+1, carry, result);
            if(!carry.empty())
                carry.erase(carry.size() - 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> letter;
        string carry;
        vector<string> result;
        
        for(int i=0;i<digits.size();i++){
            if(digits[i] == '7')
                letter.push_back("pqrs");
            else if(digits[i] == '8')
                letter.push_back("tuv");
            else if(digits[i] == '9')
                letter.push_back("wxyz");
            else{
                string s;
                for(int j=0;j<3;j++)
                    s += ((digits[i] - '0') - 2)*3 + 'a' + j;
                letter.push_back(s);
            }
        }
        if(digits.empty())
            return result;
        combination(letter, 0, carry, result);
        return result;
    }
};
