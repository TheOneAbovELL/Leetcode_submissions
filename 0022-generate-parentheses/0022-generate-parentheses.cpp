class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        function<void(string,int,int)> dfs=[&](string cur,int open,int close){
            if(cur.size()==2*n){
                res.push_back(cur);
                return;
            }
            if(open<n) dfs(cur+'(',open+1,close);
            if(close<open) dfs(cur+')',open,close+1);
        };
        dfs("",0,0);
        return res;
    }
};