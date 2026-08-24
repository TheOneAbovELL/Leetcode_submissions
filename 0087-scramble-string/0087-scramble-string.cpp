class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        unordered_map<string,bool> memo;
        function<bool(string,string)> dfs=[&](string a,string b){
            if(a==b) return true;
            string key=a+"#"+b;
            if(memo.count(key)) return memo[key];
            int m=a.size();
            string x=a,y=b;
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            if(x!=y) return memo[key]=false;
            for(int i=1;i<m;i++){
                if(dfs(a.substr(0,i),b.substr(0,i)) && dfs(a.substr(i),b.substr(i)))
                    return memo[key]=true;
                if(dfs(a.substr(0,i),b.substr(m-i)) && dfs(a.substr(i),b.substr(0,m-i)))
                    return memo[key]=true;
            }
            return memo[key]=false;
        };
        return dfs(s1,s2);
    }
};