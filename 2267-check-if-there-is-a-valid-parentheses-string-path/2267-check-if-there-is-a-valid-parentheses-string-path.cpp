class Solution {
    bool v[100][100][105];
    int m,n;
    bool dfs(int i, int j, int k, vector< vector< char > >& g){
        if(i>=m||j>=n) return 0;
        k+=g[i][j]=='('?1:-1;
        if(k<0||k>(m+n-1)/2) return 0;
        if(i==m-1&&j==n-1) return k==0;
        if(v[i][j][k]) return 0;
        v[i][j][k]=1;
        return dfs(i+1,j,k,g)||dfs(i,j+1,k,g);
    }
public:
    bool hasValidPath(vector< vector< char > >& g) {
        m=g.size(); n=g[0].size();
        if((m+n-1)%2) return 0;
        memset(v,0,sizeof(v));
        return dfs(0,0,0,g);
    }
};