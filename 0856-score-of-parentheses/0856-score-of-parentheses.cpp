class Solution {
public:
    int scoreOfParentheses(string s) {
        int r=0,d=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(') d++;
            else{
                d--;
                if(s[i-1]=='(') r+=1<<d;
            }
        }
        return r;
    }
};