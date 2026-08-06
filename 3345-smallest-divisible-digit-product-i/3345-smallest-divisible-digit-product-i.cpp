class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            int prod=1,x=i;
            while(x){
                prod*=x%10;
                x/=10;
            }
            if(prod%t==0) return i;
        }
    }
};