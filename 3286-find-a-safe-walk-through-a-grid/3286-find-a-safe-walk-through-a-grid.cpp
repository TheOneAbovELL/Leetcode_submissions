class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(health+1,false)));
        queue<tuple<int,int,int>> q;
        int startHealth=health-grid[0][0];
        if(startHealth<1) return false;
        q.push({0,0,startHealth});
        vis[0][0][startHealth]=true;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto [x,y,h]=q.front();q.pop();
            if(x==m-1&&y==n-1) return true;
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx>=0&&nx<m&&ny>=0&&ny<n){
                    int nh=h-grid[nx][ny];
                    if(nh>=1&&!vis[nx][ny][nh]){
                        vis[nx][ny][nh]=true;
                        q.push({nx,ny,nh});
                    }
                }
            }
        }
        return false;
    }
};