class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=2;i<=n;i++){
            string t="";
            int cnt=1;
            for(int j=1;j<=s.size();j++){
                if(j<s.size()&&s[j]==s[j-1]) cnt++;
                else{
                    t+=to_string(cnt)+s[j-1];
                    cnt=1;
                }
            }
            s=t;
        }
        return s;
    }
};