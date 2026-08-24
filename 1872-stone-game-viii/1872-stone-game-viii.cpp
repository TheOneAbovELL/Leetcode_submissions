class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<long long> pref(n,0);
        pref[0]=stones[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+stones[i];
        long long res=pref[n-1];
        for(int i=n-2;i>=1;i--){
            res=max(res,pref[i]-res);
        }
        return res;
    }
};