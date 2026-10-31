class Solution {
    int m, n;
    long long MOD = 1e9 + 7;
    pair<int, int> memo_jump[505][505][2];
    int memo_dp[505][505];
    pair<int, int> getJump(int r, int c, int dir, vector<vector<int>>& grid) {
        if(r >= m || c >= n) return {-1, -1};
        if(memo_jump[r][c][dir].first != -2) return memo_jump[r][c][dir];
        if(grid[r][c] == 0) return memo_jump[r][c][dir] = {r, c};
        if(dir == 0) return memo_jump[r][c][dir] = getJump(r + 1, c, 1, grid);
        return memo_jump[r][c][dir] = getJump(r, c + 1, 0, grid);
    }
    int getPaths(int r, int c, vector<vector<int>>& grid) {
        if(r == m - 1 && c == n - 1) return 1;
        if(memo_dp[r][c] != -1) return memo_dp[r][c];
        long long paths = 0;
        if(c + 1 < n) {
            auto dest = getJump(r, c + 1, 0, grid);
            if(dest.first != -1) paths = (paths + getPaths(dest.first, dest.second, grid)) % MOD;
        }
        if(r + 1 < m) {
            auto dest = getJump(r + 1, c, 1, grid);
            if(dest.first != -1) paths = (paths + getPaths(dest.first, dest.second, grid)) % MOD;
        }
        return memo_dp[r][c] = paths;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                memo_dp[i][j] = -1;
                memo_jump[i][j][0] = {-2, -2};
                memo_jump[i][j][1] = {-2, -2};
            }
        }
        return getPaths(0, 0, grid);
    }
};