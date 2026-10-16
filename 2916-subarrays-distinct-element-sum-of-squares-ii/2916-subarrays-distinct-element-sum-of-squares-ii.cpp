class Solution {
    long long ts[400005], tsm[400005], lz[400005];
    long long M=1e9+7;
    void p(int n, int l, int r) {
        if(lz[n]){
            int m=(l+r)/2, L=n*2, R=n*2+1;
            long long x=lz[n], ll=m-l+1, lr=r-m;
            ts[L]=(ts[L]+2*x*tsm[L]+x*x%M*ll)%M;
            tsm[L]=(tsm[L]+x*ll)%M;
            lz[L]=(lz[L]+x)%M;
            ts[R]=(ts[R]+2*x*tsm[R]+x*x%M*lr)%M;
            tsm[R]=(tsm[R]+x*lr)%M;
            lz[R]=(lz[R]+x)%M;
            lz[n]=0;
        }
    }
    void u(int n, int l, int r, int ql, int qr) {
        if(ql<=l&&r<=qr){
            long long len=r-l+1;
            ts[n]=(ts[n]+2*tsm[n]+len)%M;
            tsm[n]=(tsm[n]+len)%M;
            lz[n]=(lz[n]+1)%M;
            return;
        }
        p(n,l,r);
        int m=(l+r)/2;
        if(ql<=m) u(n*2,l,m,ql,qr);
        if(qr>m) u(n*2+1,m+1,r,ql,qr);
        tsm[n]=(tsm[n*2]+tsm[n*2+1])%M;
        ts[n]=(ts[n*2]+ts[n*2+1])%M;
    }
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        memset(ts,0,sizeof(ts));
        memset(tsm,0,sizeof(tsm));
        memset(lz,0,sizeof(lz));
        vector<int> lst(100005,-1);
        long long ans=0;
        for(int i=0;i<n;++i){
            u(1,0,n-1,lst[nums[i]]+1,i);
            ans=(ans+ts[1])%M;
            lst[nums[i]]=i;
        }
        return ans;
    }
};