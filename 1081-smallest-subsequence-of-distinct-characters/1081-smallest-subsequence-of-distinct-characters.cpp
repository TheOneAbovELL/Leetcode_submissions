class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,0),vis(26,0);
        for(int i=0;i<s.size();i++) last[s[i]-'a']=i;
        string res="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(vis[c-'a']) continue;
            while(!res.empty()&&res.back()>c&&last[res.back()-'a']>i){
                vis[res.back()-'a']=0;
                res.pop_back();
            }
            res.push_back(c);
            vis[c-'a']=1;
        }
        return res;
    }
};