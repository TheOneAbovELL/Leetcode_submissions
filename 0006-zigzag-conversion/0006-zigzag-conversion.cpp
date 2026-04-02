class Solution {
public:
    string convert(string s, int numrows) {
        if(numrows==1) return s;
        vector<string> rows(numrows);
        int cur=0, dir=1;
        for(char c:s){
            rows[cur]+=c;
            cur+=dir;
            if(cur==0||cur==numrows-1) dir=-dir;
        }
        string res;
        for(string& r:rows) res+=r;
        return res;
    }
};