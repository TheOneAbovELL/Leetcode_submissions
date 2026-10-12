class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> c(32,0);
        for(int x:nums){
            for(int i=0;i<32;++i){
                if((x>>i)&1) c[i]++;
            }
        }
        long long r=0,m=1e9+7;
        while(k--){
            long long v=0;
            for(int i=0;i<32;++i){
                if(c[i]>0){ v|=(1LL<<i); c[i]--; }
            }
            r=(r+(v*v)%m)%m;
        }
        return r;
    }
};