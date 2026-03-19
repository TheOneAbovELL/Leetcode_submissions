class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
        vector<vector<pair<int,int>>>dp(m+1,vector<pair<int,int>>(n+1,{0,0}));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                auto& cur=dp[i][j];
                cur.first=dp[i-1][j].first+dp[i][j-1].first-dp[i-1][j-1].first;
                cur.second=dp[i-1][j].second+dp[i][j-1].second-dp[i-1][j-1].second;
                if(grid[i-1][j-1]=='X')cur.first++;
                if(grid[i-1][j-1]=='Y')cur.second++;
                if(cur.first>0&&cur.first==cur.second)res++;
            }
        }
        return res;
    }
};