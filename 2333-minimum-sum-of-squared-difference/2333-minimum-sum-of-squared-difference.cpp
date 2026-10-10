class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k=k1+0LL+k2,r=0,m=0;
        vector<long long> c(100005,0);
        for(int i=0;i<nums1.size();++i){
            int d=abs(nums1[i]-nums2[i]);
            c[d]++;
            if(d>m) m=d;
        }
        for(long long i=m;i>0&&k>0;--i){
            long long t=min(k,c[i]);
            c[i]-=t;
            c[i-1]+=t;
            k-=t;
        }
        for(long long i=1;i<=m;++i) r+=i*i*c[i];
        return r;
    }
};