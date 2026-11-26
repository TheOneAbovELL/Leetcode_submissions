class Solution {
public:
    bool canAliceWin(int n) {
        int x=10,t=0;
        while(n>=x){n-=x--;t++;}
        return t%2;
    }
};