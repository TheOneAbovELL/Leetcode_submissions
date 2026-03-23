class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        long long maxProd=-1;
        function<void(int,int,long long)>dfs=[&](int i,int j,long long prod){
            prod*=grid[i][j];
            if(i==m-1&&j==n-1){
                if(prod>=0)maxProd=max(maxProd,prod);
                return;
            }
            if(prod==0){
                maxProd=max(maxProd,0LL);
                return;
            }
            if(i+1<m)dfs(i+1,j,prod);
            if(j+1<n)dfs(i,j+1,prod);
        };
        dfs(0,0,1);
        return maxProd>=0?maxProd%1000000007:-1;
    }
};