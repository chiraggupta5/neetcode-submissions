class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector < vector < bool > > visited(n, vector < bool > (m, false)); 
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    q.push({i,j});
                    visited[i][j] = true;
                    ans++;
                }
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int a = -1; a <= 1; a++){
                        for(int b = -1; b <= 1; b++){
                            int nx = x+a;
                            int ny = y+b;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && abs(a)!=abs(b) && !visited[nx][ny] && grid[nx][ny] == '1'){
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
