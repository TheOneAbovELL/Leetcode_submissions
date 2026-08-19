class Solution {
public:
    int countDigitOne(int n) {
        long long count=0;
        for(long long i=1;i<=n;i*=10){
            long long high=n/(i*10);
            long long cur=(n/i)%10;
            long long low=n%i;
            if(cur==0) count+=high*i;
            else if(cur==1) count+=high*i+low+1;
            else count+=(high+1)*i;
        }
        return count;
    }
};