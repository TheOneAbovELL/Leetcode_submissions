class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector< int > p(n),st;
        for(int i=0;i<n;++i){
            if(s[i]=='(') st.push_back(i);
            else if(s[i]==')'){
                int j=st.back(); st.pop_back();
                p[i]=j; p[j]=i;
            }
        }
        string r;
        for(int i=0,d=1;i<n;i+=d){
            if(s[i]=='('||s[i]==')') i=p[i],d=-d;
            else r+=s[i];
        }
        return r;
    }
};