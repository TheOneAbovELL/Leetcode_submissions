class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        vector<long long> dp(26,0);
        for(char c:s){
            int idx=c-'a';
            long long total=0;
            for(int i=0;i<26;i++) total=(total+dp[i])%mod;
            dp[idx]=(total+1)%mod;
        }
        long long res=0;
        for(int i=0;i<26;i++) res=(res+dp[i])%mod;
        return res;
    }
};