class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        auto can=[&](int limit){
            if(dist[0][0]<limit) return false;
            vector<vector<bool>> vis(n,vector<bool>(n,false));
            queue<pair<int,int>> qq;
            qq.push({0,0});
            vis[0][0]=true;
            while(!qq.empty()){
                auto [x,y]=qq.front();qq.pop();
                if(x==n-1&&y==n-1) return true;
                for(int d=0;d<4;d++){
                    int nx=x+dx[d],ny=y+dy[d];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis[nx][ny]&&dist[nx][ny]>=limit){
                        vis[nx][ny]=true;
                        qq.push({nx,ny});
                    }
                }
            }
            return false;
        };
        int l=0,r=n*2,res=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(can(mid)){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return res;
    }
};