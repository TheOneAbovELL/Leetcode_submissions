class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size();
        if(m+n!=s3.size()) return false;
        vector<bool> dp(n+1,false);
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0&&j==0) dp[j]=true;
                else if(i==0) dp[j]=dp[j-1]&&s2[j-1]==s3[j-1];
                else if(j==0) dp[j]=dp[j]&&s1[i-1]==s3[i-1];
                else dp[j]=(dp[j]&&s1[i-1]==s3[i+j-1])||(dp[j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[n];
    }
};