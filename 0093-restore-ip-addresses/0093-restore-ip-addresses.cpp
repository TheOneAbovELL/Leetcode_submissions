class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n=s.size();
        if(n<4||n>12) return res;
        function<void(int,int,string)> dfs=[&](int idx,int parts,string cur){
            if(parts==4){
                if(idx==n) res.push_back(cur);
                return;
            }
            for(int len=1;len<=3;len++){
                if(idx+len>n) break;
                string sub=s.substr(idx,len);
                if((sub[0]=='0'&&len>1)||stoi(sub)>255) continue;
                dfs(idx+len,parts+1,cur+(parts==0?"":".")+sub);
            }
        };
        dfs(0,0,"");
        return res;
    }
};