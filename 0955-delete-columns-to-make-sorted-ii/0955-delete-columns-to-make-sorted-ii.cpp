class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int res = 0;
        
        for (int j = 0; j < m; j++) {
            int i;
            for (i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if (i == n - 1) {
                for (int k = 0; k < n - 1; k++) {
                    if (strs[k][j] < strs[k + 1][j]) {
                        sorted[k] = true;
                    }
                }
            }
        }
        return res;
    }
};