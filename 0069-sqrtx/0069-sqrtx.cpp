class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        long long l=1,r=x,ans=0;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(m*m<=x){
                ans=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
};