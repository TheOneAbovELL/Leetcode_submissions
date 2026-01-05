class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int minAbs = INT_MAX;
        int negativeCount = 0;
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                total += abs(val);
                minAbs = min(minAbs, abs(val));
                if (val < 0) negativeCount++;
            }
        }
        
        if (negativeCount % 2 == 0) return total;
        return total - 2 * minAbs;
    }
};