class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    if (i == 0 && j == 0) continue;
                    int newMod = (r - (grid[i][j] % k) + k) % k;
                    if (i > 0) {
                        dp[i][j][r] = (dp[i][j][r] + dp[i-1][j][newMod]) % MOD;
                    }
                    if (j > 0) {
                        dp[i][j][r] = (dp[i][j][r] + dp[i][j-1][newMod]) % MOD;
                    }
                }
            }
        }
        
        return dp[m-1][n-1][0];
    }
};