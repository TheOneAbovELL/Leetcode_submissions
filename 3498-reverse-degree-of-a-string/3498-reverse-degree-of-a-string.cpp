class Solution {
public:
    int reverseDegree(string s) {
        int a=0,n=s.size();
        for(int i=0;i<n;++i) a+=(26-(s[i]-'a'))*(i+1);
        return a;
    }
};