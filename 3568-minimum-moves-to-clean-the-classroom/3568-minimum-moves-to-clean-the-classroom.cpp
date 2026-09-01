class Solution {
public:
    int minMoves(vector<string>& a, int e) {
        int r=a.size(), c=a[0].size(), x, y, l=0;
        int t[20][20], f[20][20][1024]; 
        memset(t,-1,sizeof(t)); memset(f,-1,sizeof(f));
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(a[i][j]=='S'){ x=i; y=j; }
                else if(a[i][j]=='L') t[i][j]=l++;
            }
        }
        if(!l) return 0;
        queue<tuple<int,int,int,int,int>> q;
        q.push({x,y,0,e,0}); f[x][y][0]=e;
        int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(q.size()){
            auto [u,v,w,p,s]=q.front(); q.pop();
            if(p==0) continue;
            for(auto& h:d){
                int i=u+h[0], j=v+h[1];
                if(i<0||i>=r||j<0||j>=c||a[i][j]=='X') continue;
                int np=(a[i][j]=='R')?e:p-1, nw=w;
                if(t[i][j]!=-1) nw|=(1<<t[i][j]);
                if(nw==(1<<l)-1) return s+1;
                if(np>f[i][j][nw]){
                    f[i][j][nw]=np;
                    q.push({i,j,nw,np,s+1});
                }
            }
        }
        return -1;
    }
};