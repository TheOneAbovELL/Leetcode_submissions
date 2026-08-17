class Solution {
    int dp[505][505];
    int p[505];
    int dfs(int l, int r){
        if(l==r) return 0;
        if(dp[l][r]) return dp[l][r];
        int res=0;
        for(int k=l;k<r;k++){
            int left=p[k]-p[l-1];
            int right=p[r]-p[k];
            if(left<right) res=max(res,left+dfs(l,k));
            else if(left>right) res=max(res,right+dfs(k+1,r));
            else res=max({res,left+dfs(l,k),right+dfs(k+1,r)});
        }
        return dp[l][r]=res;
    }
public:
    int stoneGameV(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++) p[i+1]=p[i]+v[i];
        memset(dp,0,sizeof(dp));
        return dfs(1,n);
    }
};