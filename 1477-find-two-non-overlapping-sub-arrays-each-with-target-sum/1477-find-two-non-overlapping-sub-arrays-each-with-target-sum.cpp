class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(),i=1e9;
        vector<int> dp(n,i);
        unordered_map<int,int> mp;
        mp[0]=-1;
        int s=0,b=i,r=i;
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(mp.count(s-target)){
                int j=mp[s-target];
                int len=i-j;
                if(j>=0&&dp[j]!=i) r=min(r,dp[j]+len);
                b=min(b,len);
            }
            dp[i]=b;
            mp[s]=i;
        }
        return r==i?-1:r;
    }
};