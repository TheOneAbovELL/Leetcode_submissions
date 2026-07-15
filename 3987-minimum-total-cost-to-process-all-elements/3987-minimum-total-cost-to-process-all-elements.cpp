class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const int MOD=1e9+7;
        long long resources=k, ops=0, cost=0;
        for(int x:nums){
            if(resources<x){
                long long need=x-resources, add=(need+k-1)/k;
                resources+=add*k;
                long long first=ops+1, last=ops+add, sum=(first+last)%MOD, cnt=add%MOD;
                cost=(cost+sum*cnt%MOD*((MOD+1)/2))%MOD;
                ops+=add;
            }
            resources-=x;
        }
        return cost%MOD;
    }
};