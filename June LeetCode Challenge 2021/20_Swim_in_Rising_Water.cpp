class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    
    struct comparator{
      bool operator() (vector<int>& a, vector<int>& b){
          return a[0] > b[0]; 
      }  
    };
    
    int swimInWater(vector<vector<int>>& A) {
        int t = 0, N = A.size();
        vector<vector<bool>> visit(N, vector<bool>(N, false));
        priority_queue<vector<int>, vector<vector<int>>, comparator> q;
        q.push({A[0][0], 0, 0});
        visit[0][0] = true;
        vector<int> curr;
        int x, y, newX, newY;
        
        while(!q.empty()){
            curr = q.top();
            q.pop();
            if(curr[1] == N-1 && curr[2] == N-1)
                return curr[0];
            t = curr[0];
            x = curr[1];
            y = curr[2];
            // cout<<x<<", "<<y<<"\n";
            for(int i=1; i<=4; i++){
                newX = x + dir[i];
                newY = y + dir[i-1];
                if(newX <0 || newX >= N || newY < 0 || newY >= N || visit[newX][newY])
                    continue;
                if(A[newX][newY] > t){
                    q.push({A[newX][newY], newX, newY});   
                }
                else
                    q.push({t, newX, newY});
                visit[newX][newY] = true;
            }
        }
        return t;
    }
};
