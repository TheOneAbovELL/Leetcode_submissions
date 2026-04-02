class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> rows(numRows);
        int cur=0, dir=1;
        for(char c:s){
            rows[cur]+=c;
            cur+=dir;
            if(cur==0||cur==numRows-1) dir=-dir;
        }
        string res;
        for(string& r:rows) res+=r;
        return res;
    }
};