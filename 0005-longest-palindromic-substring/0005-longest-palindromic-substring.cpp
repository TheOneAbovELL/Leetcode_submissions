class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(),start=0,maxLen=1;
        auto expand=[&](int l,int r){
            while(l>=0&&r<n&&s[l]==s[r]){
                if(r-l+1>maxLen){
                    start=l;
                    maxLen=r-l+1;
                }
                l--;r++;
            }
        };
        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxLen);
    }
};