/********** Recursive Approach **********/

class Solution {
public:
    bool isSquare(vector<int>& m, int n, int a, int b, int c, int d){
        if(n == 0){
            if(a == 0 && b == 0 && c == 0 && d == 0)
                return true;
            return false;
        }
        int val = m[n-1];
        bool result = false;
        if(a >= val)
            result = result || isSquare(m,n-1,a-val,b,c,d);
        if(!result && b >= val)
            result = result || isSquare(m,n-1,a,b-val,c,d);
        if(!result && c >= val)
            result = result || isSquare(m,n-1,a,b,c-val,d);
        if(!result && d >= val)
            result = result || isSquare(m,n-1,a,b,c,d-val);
        return result;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto& stick : matchsticks)
            sum += stick;
        if((sum % 4) != 0)  return false;
        int edge = sum/4;
        return isSquare(matchsticks, matchsticks.size(), edge, edge, edge, edge);
    }
};

