class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]+stones[i];
        vector<long long> dp(n+1,0);
        dp[n-1]=pref[n];
        for(int i=n-2;i>=1;i--){
            dp[i]=max(pref[i+1]-dp[i+1],dp[i+1]);
        }
        return dp[1];
    }
};