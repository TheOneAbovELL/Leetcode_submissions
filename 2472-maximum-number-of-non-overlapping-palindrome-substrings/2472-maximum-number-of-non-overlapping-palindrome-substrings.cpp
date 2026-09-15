class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<char>> p(n,vector<char>(n,0));
        for(int d=0;d<n;d++){
            for(int i=0;i+d<n;i++){
                if(s[i]==s[i+d]&&(d<=1||p[i+1][i+d-1])) p[i][i+d]=1;
            }
        }
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            for(int j=0;j<=i-k;j++){
                if(p[j][i-1]) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return dp[n];
    }
};