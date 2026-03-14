class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string>happy;
        string cur;
        function<void()>dfs=[&](){
            if(cur.size()==n){
                happy.push_back(cur);
                return;
            }
            for(char c='a';c<='c';c++){
                if(cur.empty()||c!=cur.back()){
                    cur.push_back(c);
                    dfs();
                    cur.pop_back();
                }
            }
        };
        dfs();
        return k<=happy.size()?happy[k-1]:"";
    }
};