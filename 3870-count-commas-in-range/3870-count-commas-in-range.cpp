class Solution {
public:
    int countCommas(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            int len=s.size();
            if(len>3) res+=(len-1)/3;
        }
        return res;
    }
};