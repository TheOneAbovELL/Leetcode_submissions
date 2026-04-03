class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int row=0,col=n-1,res=0;
        while(row<m && col>=0){
            if(grid[row][col]<0){
                res+=m-row;
                col--;
            }else{
                row++;
            }
        }
        return res;
    }
};