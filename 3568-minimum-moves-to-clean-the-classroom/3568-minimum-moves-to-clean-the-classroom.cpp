class Solution {
public:
    int minMoves(vector<string>& g, int e) {
        int m=g.size(),n=g[0].size(),sr,sc,k=0;
        int lx[20][20]; memset(lx,-1,sizeof(lx));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(g[i][j]=='S'){sr=i;sc=j;}
                else if(g[i][j]=='L') lx[i][j]=k++;
            }
        }
        if(!k) return 0;
        int mx[20][20][1024]; memset(mx,-1,sizeof(mx));
        queue<tuple<int,int,int,int,int>> q;
        q.push({sr,sc,0,e,0}); mx[sr][sc][0]=e;
        int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(q.size()){
            auto [r,c,mask,en,mv]=q.front(); q.pop();
            if(en==0) continue;
            for(auto& i:d){
                int nr=r+i[0],nc=c+i[1];
                if(nr<0||nr>=m||nc<0||nc>=n||g[nr][nc]=='X') continue;
                int ne=(g[nr][nc]=='R')?e:en-1,nm=mask;
                if(lx[nr][nc]!=-1) nm|=(1<<lx[nr][nc]);
                if(nm==(1<<k)-1) return mv+1;
                if(ne>mx[nr][nc][nm]){
                    mx[nr][nc][nm]=ne;
                    q.push({nr,nc,nm,ne,mv+1});
                }
            }
        }
        return -1;
    }
};