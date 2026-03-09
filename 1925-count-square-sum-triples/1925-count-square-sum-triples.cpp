class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        vector<bool> sq(n*n+1,false);
        for(int i=1;i<=n;i++) sq[i*i]=true;
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                int s=a*a+b*b;
                if(s<=n*n && sq[s]) cnt++;
            }
        }
        return cnt;
    }
};