class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int layers=min(m,n)/2;
        for(int layer=0;layer<layers;layer++){
            int top=layer,bottom=m-1-layer;
            int left=layer,right=n-1-layer;
            vector<int> elements;
            for(int j=left;j<=right;j++) elements.push_back(grid[top][j]);
            for(int i=top+1;i<=bottom;i++) elements.push_back(grid[i][right]);
            for(int j=right-1;j>=left;j--) elements.push_back(grid[bottom][j]);
            for(int i=bottom-1;i>top;i--) elements.push_back(grid[i][left]);
            int len=elements.size();
            int shift=k%len;
            if(shift==0) continue;
            vector<int> rotated(len);
            for(int i=0;i<len;i++){
                rotated[i]=elements[(i+shift)%len];
            }
            int idx=0;
            for(int j=left;j<=right;j++) grid[top][j]=rotated[idx++];
            for(int i=top+1;i<=bottom;i++) grid[i][right]=rotated[idx++];
            for(int j=right-1;j>=left;j--) grid[bottom][j]=rotated[idx++];
            for(int i=bottom-1;i>top;i--) grid[i][left]=rotated[idx++];
        }
        return grid;
    }
};