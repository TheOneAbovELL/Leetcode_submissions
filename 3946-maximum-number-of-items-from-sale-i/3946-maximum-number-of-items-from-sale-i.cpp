class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int cnt[1501]={},g[1501]={};
        for(auto& x:items) cnt[x[0]]++;
        for(int i=1;i<=1500;++i)
            for(int j=i;j<=1500;j+=i) g[i]+=cnt[j];
        sort(items.begin(),items.end(),[](auto& a,auto& b){return a[1]>b[1];});
        vector<int> dp(budget+1,-1);
        dp[0]=0;
        int ans=0;
        for(auto& x:items){
            int v=g[x[0]],p=x[1];
            for(int c=0;c+p<=budget;++c)
                if(dp[c]!=-1) ans=max(ans,dp[c]+v+(budget-c-p)/p);
            for(int c=budget;c>=p;--c)
                if(dp[c-p]!=-1) dp[c]=max(dp[c],dp[c-p]+v);
        }
        return ans;
    }
};