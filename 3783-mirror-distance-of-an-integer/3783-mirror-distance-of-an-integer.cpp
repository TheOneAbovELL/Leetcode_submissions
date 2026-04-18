class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0,t=n;
        while(t){
            rev=rev*10+t%10;
            t/=10;
        }
        return abs(n-rev);
    }
};