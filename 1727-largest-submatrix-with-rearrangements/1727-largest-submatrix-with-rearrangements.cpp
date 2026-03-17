class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0&&matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
            vector<int>row=matrix[i];
            sort(row.begin(),row.end(),greater<int>());
            for(int j=0;j<n;j++){
                res=max(res,row[j]*(j+1));
            }
        }
        return res;
    }
};