class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int pos, sum = 0;
        unordered_map<int,int> bound;
        int max_edge = 0;
        
        for(auto row : wall){
            pos = 0;
            for(int i=0; i<row.size()-1; i++){
                pos += row[i];
                bound[pos]++;
                max_edge = max(max_edge, bound[pos]);
            }
        }
    
        return wall.size()-max_edge;
    }
};
