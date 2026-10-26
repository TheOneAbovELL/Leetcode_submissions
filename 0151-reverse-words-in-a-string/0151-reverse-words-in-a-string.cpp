class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size(),l=0,i=0;
        while(i<n){
            while(i<n&&s[i]==' ') i++;
            if(i==n) break;
            if(l>0) s[l++]=' ';
            int j=l;
            while(i<n&&s[i]!=' ') s[l++]=s[i++];
            reverse(s.begin()+j,s.begin()+l);
        }
        s.resize(l);
        return s;
    }
};