class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>> res(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++){
            int empty=n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    res[empty][m-1-i]='#';
                    empty--;
                }else if(boxGrid[i][j]=='*'){
                    res[j][m-1-i]='*';
                    empty=j-1;
                }
            }
        }
        return res;
    }
};