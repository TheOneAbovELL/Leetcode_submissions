class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;
        unordered_set<string>seen;
        for(int i=0;i<=s.size()-k;i++){
            seen.insert(s.substr(i,k));
        }
        return seen.size()==(1<<k);
    }
};