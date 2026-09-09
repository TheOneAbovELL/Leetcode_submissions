class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
        long long power=1000;
        while(power<=n){
            res+=n-power+1;
            power*=1000;
        }
        return res;
    }
};