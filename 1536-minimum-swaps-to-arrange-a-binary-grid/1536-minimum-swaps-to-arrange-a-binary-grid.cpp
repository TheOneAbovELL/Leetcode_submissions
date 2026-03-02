class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> last(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    last[i] = j;
                    break;
                }
            }
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int target = -1;
            for (int j = i; j < n; j++) {
                if (last[j] <= i) {
                    target = j;
                    break;
                }
            }
            if (target == -1) return -1;
            for (int k = target; k > i; k--) {
                swap(last[k], last[k - 1]);
                swaps++;
            }
        }
        return swaps;
    }
};