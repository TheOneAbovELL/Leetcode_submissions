class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        vector<long long>flat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                flat.push_back(grid[i][j]%12345);
            }
        }
        int sz=flat.size();
        vector<long long>prefix(sz,1),suffix(sz,1);
        for(int i=1;i<sz;i++){
            prefix[i]=(prefix[i-1]*flat[i-1])%12345;
        }
        for(int i=sz-2;i>=0;i--){
            suffix[i]=(suffix[i+1]*flat[i+1])%12345;
        }
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=(prefix[idx]*suffix[idx])%12345;
                idx++;
            }
        }
        return res;
    }
};