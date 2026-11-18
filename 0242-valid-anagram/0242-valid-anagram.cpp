class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int c[26]={0};
        for(int i=0;i<s.size();++i){c[s[i]-'a']++;c[t[i]-'a']--;}
        for(int x:c) if(x) return false;
        return true;
    }
};