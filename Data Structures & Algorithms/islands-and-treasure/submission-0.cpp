class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int inf = pow(2,31)-1;
        vector < vector < int > > visited(n, vector < int > (m, inf)); 
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = 0;
                }
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int a = -1; a <= 1; a++){
                        for(int b = -1; b <= 1; b++){
                            int nx = x+a;
                            int ny = y+b;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && abs(a)!=abs(b) && visited[nx][ny]>visited[x][y]+1 && grid[nx][ny] != -1){
                                q.push({nx, ny});
                                visited[nx][ny] = visited[x][y]+1;
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]!=-1){
                    grid[i][j] = visited[i][j];
                }
            }
        }
    }
};
