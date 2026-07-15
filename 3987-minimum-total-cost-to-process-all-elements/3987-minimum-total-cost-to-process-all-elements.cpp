class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const int MOD=1e9+7;
        long long resources=k;
        long long ops=0;
        long long cost=0;
        for(int x:nums){
            if(resources<x){
                long long need=x-resources;
                long long add=(need+k-1)/k;
                resources+=add*k;
                long long first=ops+1;
                long long last=ops+add;
                long long sum=(first+last)%MOD;
                long long cnt=add%MOD;
                cost=(cost+sum*cnt%MOD*((MOD+1)/2))%MOD;
                ops+=add;
            }
            resources-=x;
        }
        return cost%MOD;
    }
};