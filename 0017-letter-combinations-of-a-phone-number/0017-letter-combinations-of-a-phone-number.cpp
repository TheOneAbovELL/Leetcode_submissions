class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res={""};
        for(char d:digits){
            vector<string> tmp;
            for(string s:res){
                for(char c:map[d-'0']){
                    tmp.push_back(s+c);
                }
            }
            res=tmp;
        }
        return res;
    }
};