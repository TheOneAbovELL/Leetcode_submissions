class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int max1=0,max2=0;
        for(char c:s){
            int d=c-'0';
            if(d>max1){
                max2=max1;
                max1=d;
            }else if(d>max2){
                max2=d;
            }
        }
        return max1*max2;
    }
};