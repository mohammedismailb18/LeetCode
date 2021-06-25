class Solution {
public:
    int rank[1001], parent[1001];
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0; i<=1000; i++)
            rank[i] = 1, parent[i] = i;
        int x,y;
        for(auto edge : edges){
            x = find(edge[0]);
            y = find(edge[1]);
            if(x != y){
                if(rank[x] > rank[y])
                    parent[y] = x;
                else if(rank[x] < rank[y])
                    parent[x] = y;
                else{
                    parent[y] = x;
                    rank[x]++;
                }
            }
            else
                return edge;
        }
        return {};
    }
    
    int find(int i){
        if(parent[i] == i)
            return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }
};
