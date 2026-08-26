class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int minLen=INT_MAX;
        string res="";
        for(int i=0;i<n;i++){
            int ones=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1') ones++;
                if(ones>k) break;
                if(ones==k){
                    int len=j-i+1;
                    string sub=s.substr(i,len);
                    if(len<minLen){
                        minLen=len;
                        res=sub;
                    }else if(len==minLen && sub<res){
                        res=sub;
                    }
                    break;
                }
            }
        }
        return res;
    }
};