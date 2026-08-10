class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> f;
        for(char c:s) f[c]++;
        vector<pair<int,char>> v;
        for(auto& p:f) v.push_back({p.second,p.first});
        sort(v.rbegin(),v.rend());
        string res;
        for(auto& p:v) res+=string(p.first,p.second);
        return res;
    }
};