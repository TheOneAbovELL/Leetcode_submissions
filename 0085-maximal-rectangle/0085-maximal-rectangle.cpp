class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size(),maxArea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    int minWidth=cols;
                    for(int k=i;k<rows&&matrix[k][j]=='1';k++){
                        int width=0;
                        while(j+width<cols&&matrix[k][j+width]=='1')width++;
                        minWidth=min(minWidth,width);
                        maxArea=max(maxArea,(k-i+1)*minWidth);
                    }
                }
            }
        }
        return maxArea;
    }
};