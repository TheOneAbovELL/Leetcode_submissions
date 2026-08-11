class Solution {
public:
    int lastRemaining(int n) {
        int head=1;
        int step=1;
        int remaining=n;
        bool ltr=true;
        while(remaining>1)  {
            if(ltr||remaining%2!=0){
                head+=step;
            }
            remaining/=2;
            step*=2;
            ltr=!ltr;
        }
        return head;
    }
};