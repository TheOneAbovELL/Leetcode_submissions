class Solution {
public:
    int minimumChanges(string s, int k) {
        int n=s.size();
        vector<vector<int>> cost(n,vector<int>(n,1e9));
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int L=j-i+1,mc=1e9;
                for(int d=1;d<L;++d){
                    if(L%d==0){
                        int cnt=L/d,cc=0;
                        for(int g=0;g<d;++g){
                            for(int p=0;p<cnt/2;++p){
                                if(s[i+g+p*d]!=s[i+g+(cnt-1-p)*d]) cc++;
                            }
                        }
                        mc=min(mc,cc);
                    }
                }
                cost[i][j]=mc;
            }
        }
        vector<vector<int>> dp(k+1,vector<int>(n,1e9));
        for(int j=1;j<n;++j) dp[1][j]=cost[0][j];
        for(int p=2;p<=k;++p){
            for(int j=p*2-1;j<n;++j){
                for(int i=p*2-3;i<=j-2;++i){
                    if(dp[p-1][i]!=1e9&&cost[i+1][j]!=1e9)
                        dp[p][j]=min(dp[p][j],dp[p-1][i]+cost[i+1][j]);
                }
            }
        }
        return dp[k][n-1];
    }
};