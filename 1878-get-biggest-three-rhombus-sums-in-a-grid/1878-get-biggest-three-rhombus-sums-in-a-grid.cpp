class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        set<int>sums;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sums.insert(grid[i][j]);
                for(int s=1;i-s>=0&&i+s<m&&j-s>=0&&j+s<n;s++){
                    int sum=grid[i-s][j]+grid[i+s][j]+grid[i][j-s]+grid[i][j+s];
                    for(int d=1;d<s;d++){
                        sum+=grid[i-d][j+s-d];
                        sum+=grid[i+d][j+s-d];
                        sum+=grid[i+d][j-s+d];
                        sum+=grid[i-d][j-s+d];
                    }
                    sums.insert(sum);
                }
            }
        }
        vector<int>res;
        for(auto it=sums.rbegin();it!=sums.rend()&&res.size()<3;it++)res.push_back(*it);
        return res;
    }
};