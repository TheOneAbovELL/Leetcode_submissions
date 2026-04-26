class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        function<bool(int,int,int,int)> dfs=[&](int x,int y,int px,int py){
            vis[x][y]=1;
            for(auto& d:dirs){
                int nx=x+d[0],ny=y+d[1];
                if(nx<0||nx>=m||ny<0||ny>=n||grid[nx][ny]!=grid[x][y]) continue;
                if(nx==px&&ny==py) continue;
                if(vis[nx][ny]) return true;
                if(dfs(nx,ny,x,y)) return true;
            }
            return false;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&dfs(i,j,-1,-1)) return true;
            }
        }
        return false;
    }
};