class Solution {
public:
    string lexPalindromicPermutation(string s, string t) {
        int f[26]={0},c[26]={0},o=0,m=s.length()/2;
        string mid="",L1="",aL="",p="";
        for(char x:s) f[x-'a']++;
        for(int i=0;i<26;i++){
            if(f[i]%2){ o++; mid=string(1,i+'a'); }
            c[i]=f[i]/2;
        }
        if(o>1) return "";
        bool ok=true;
        int tc[26];
        for(int i=0;i<26;i++) tc[i]=c[i];
        for(int i=0;i<m;i++){
            int x=t[i]-'a';
            if(tc[x]>0){ tc[x]--; L1+=t[i]; }
            else{ ok=false; break; }
        }
        if(ok){
            string R1=L1; reverse(R1.begin(),R1.end());
            string P1=L1+mid+R1;
            if(P1>t) return P1;
        }
        for(int i=0;i<m;i++){
            for(int j=t[i]-'a'+1;j<26;j++){
                if(c[j]>0){
                    string tmp=p+(char)(j+'a');
                    c[j]--;
                    for(int k=0;k<26;k++) tmp.append(c[k],k+'a');
                    aL=tmp; c[j]++; break;
                }
            }
            if(c[t[i]-'a']>0){ p+=t[i]; c[t[i]-'a']--; }
            else break;
        }
        if(aL!=""){
            string R2=aL; reverse(R2.begin(),R2.end());
            return aL+mid+R2;
        }
        return "";
    }
};