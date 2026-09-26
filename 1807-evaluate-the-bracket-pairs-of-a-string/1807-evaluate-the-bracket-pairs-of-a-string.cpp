class Solution {
public:
    string evaluate(string s, vector< vector< string > >& k) {
        unordered_map< string, string > m;
        for(auto& x:k) m[x[0]]=x[1];
        string r="",t="";
        bool f=0;
        for(char c:s){
            if(c=='(') f=1;
            else if(c==')'){
                r+=m.count(t)?m[t]:"?";
                t=""; f=0;
            }
            else if(f) t+=c;
            else r+=c;
        }
        return r;
    }
};