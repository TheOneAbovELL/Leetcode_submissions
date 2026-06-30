class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3]={-1,-1,-1},res=0;
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
            if(last[0]!=-1&&last[1]!=-1&&last[2]!=-1){
                res+=1+min({last[0],last[1],last[2]});
            }
        }
        return res;
    }
};