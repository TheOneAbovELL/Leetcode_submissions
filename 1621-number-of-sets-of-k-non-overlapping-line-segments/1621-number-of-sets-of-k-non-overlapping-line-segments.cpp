class Solution {
public:
    int numberOfSets(int n, int k) {
        long long N=n+k-1, K=k*2, m=1e9+7, a=1, b=1;
        auto p=[&](long long x, long long y){
            long long r=1;
            while(y){
                if(y&1) r=r*x%m;
                x=x*x%m; y>>=1;
            }
            return r;
        };
        for(int i=1;i<=K;++i){
            a=a*(N-i+1)%m;
            b=b*i%m;
        }
        return a*p(b,m-2)%m;
    }
};