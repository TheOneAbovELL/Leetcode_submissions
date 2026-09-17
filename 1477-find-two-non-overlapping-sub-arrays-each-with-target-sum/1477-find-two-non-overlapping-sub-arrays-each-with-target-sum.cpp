class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(),inf=1e9;
        vector<int> dp(n,inf);
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0,best=inf,res=inf;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.count(sum-target)){
                int j=mp[sum-target];
                int len=i-j;
                if(j>=0&&dp[j]!=inf) res=min(res,dp[j]+len);
                best=min(best,len);
            }
            dp[i]=best;
            mp[sum]=i;
        }
        return res==inf?-1:res;
    }
};