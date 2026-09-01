class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n,string(n,'.'));
        auto f=[&](auto& f,int i,int c,int d1,int d2){
            if(i==n){ans.push_back(b);return;}
            for(int j=0;j<n;j++){
                int m=1<<j,p=1<<(i+j),q=1<<(i-j+n);
                if(!(c&m)&&!(d1&p)&&!(d2&q)){
                    b[i][j]='Q';
                    f(f,i+1,c|m,d1|p,d2|q);
                    b[i][j]='.';
                }
            }
        };
        f(f,0,0,0,0);
        return ans;
    }
};