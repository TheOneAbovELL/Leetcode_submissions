class Solution {
public:
    int maxDepth(string s) {
        int m=0,c=0;
        for(char x:s){
            if(x=='(') m=max(m,++c);
            else if(x==')') c--;
        }
        return m;
    }
};