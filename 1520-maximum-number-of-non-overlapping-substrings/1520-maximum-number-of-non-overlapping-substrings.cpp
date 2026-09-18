class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size(), l[26], r[26], e=-1;
        memset(l,-1,sizeof(l));
        for(int i=0;i<n;i++){
            if(l[s[i]-'a']==-1) l[s[i]-'a']=i;
            r[s[i]-'a']=i;
        }
        vector<string> a;
        for(int i=0;i<n;i++){
            if(i==l[s[i]-'a']){
                int t=r[s[i]-'a'], ok=1;
                for(int j=i;j<=t;j++){
                    if(l[s[j]-'a']<i){ ok=0; break; }
                    t=max(t,r[s[j]-'a']);
                }
                if(ok){
                    if(i>e) a.push_back("");
                    a.back()=s.substr(i,t-i+1);
                    e=t;
                }
            }
        }
        return a;
    }
};