class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>row(m+2,vector<int>(n+2,0));
        vector<vector<int>>col(m+2,vector<int>(n+2,0));
        vector<vector<int>>d1(m+2,vector<int>(n+2,0));
        vector<vector<int>>d2(m+2,vector<int>(n+2,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                row[i][j]=row[i][j-1]+grid[i-1][j-1];
                col[i][j]=col[i-1][j]+grid[i-1][j-1];
                d1[i][j]=d1[i-1][j-1]+grid[i-1][j-1];
                d2[i][j]=d2[i-1][j+1]+grid[i-1][j-1];
            }
        }
        auto getRow=[&](int r,int c1,int c2){
            return row[r][c2]-row[r][c1-1];
        };
        auto getCol=[&](int c,int r1,int r2){
            return col[r2][c]-col[r1-1][c];
        };
        auto getD1=[&](int r1,int c1,int k){
            return d1[r1+k-1][c1+k-1]-d1[r1-1][c1-1];
        };
        auto getD2=[&](int r1,int c2,int k){
            return d2[r1+k-1][c2-k+1]-d2[r1-1][c2+1];
        };
        int ans=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=min(m-i+1,n-j+1);k>ans;k--){
                    int sum=getD1(i,j,k);
                    if(getD2(i,j+k-1,k)!=sum)continue;
                    bool ok=true;
                    for(int r=i;r<i+k;r++){
                        if(getRow(r,j,j+k-1)!=sum){ok=false;break;}
                    }
                    if(!ok)continue;
                    for(int c=j;c<j+k;c++){
                        if(getCol(c,i,i+k-1)!=sum){ok=false;break;}
                    }
                    if(ok){ans=k;break;}
                }
            }
        }
        return ans;
    }
};