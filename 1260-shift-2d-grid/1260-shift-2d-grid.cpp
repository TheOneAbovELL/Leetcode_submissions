class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        int total=m*n;
        k%=total;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=(i*n+j+k)%total;
                res[idx/n][idx%n]=grid[i][j];
            }
        }
        return res;
    }
};