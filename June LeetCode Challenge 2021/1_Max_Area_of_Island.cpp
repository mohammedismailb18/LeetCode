class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, int m, int n){
        if(x<0 || x>= m || y<0 || y>=n || grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        return 1 + dfs(grid,x-1,y,m,n) + dfs(grid,x,y+1,m,n) + dfs(grid,x+1,y,m,n) + dfs(grid,x,y-1,m,n);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j])
                    area = max(area, dfs(grid, i, j, m, n));
            }
        }
        return area;
    }
};
