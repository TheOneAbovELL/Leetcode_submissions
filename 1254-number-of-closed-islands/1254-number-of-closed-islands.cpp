class Solution {
    void dfs(vector<vector<int>>& g, int r, int c) {
        if(r<0||c<0||r>=g.size()||c>=g[0].size()||g[r][c]!=0) return;
        g[r][c]=1;
        dfs(g,r+1,c);
        dfs(g,r-1,c);
        dfs(g,r,c+1);
        dfs(g,r,c-1);
    }
public:
    int closedIsland(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size(),ans=0;
        for(int i=0;i<m;++i){
            if(g[i][0]==0) dfs(g,i,0);
            if(g[i][n-1]==0) dfs(g,i,n-1);
        }
        for(int j=0;j<n;++j){
            if(g[0][j]==0) dfs(g,0,j);
            if(g[m-1][j]==0) dfs(g,m-1,j);
        }
        for(int i=1;i<m-1;++i){
            for(int j=1;j<n-1;++j){
                if(g[i][j]==0){
                    ans++;
                    dfs(g,i,j);
                }
            }
        }
        return ans;
    }
};