class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int shift=k%n;
                if(i%2==0){
                    int newJ=(j-shift+n)%n;
                    if(mat[i][j]!=mat[i][newJ]) return false;
                }else{
                    int newJ=(j+shift)%n;
                    if(mat[i][j]!=mat[i][newJ]) return false;
                }
            }
        }
        return true;
    }
};