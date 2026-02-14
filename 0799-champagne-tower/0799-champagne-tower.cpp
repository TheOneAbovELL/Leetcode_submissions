class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(101, vector<double>(101, 0.0));
        tower[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double overflow = (tower[i][j] - 1.0) / 2.0;
                if (overflow > 0) {
                    tower[i + 1][j] += overflow;
                    tower[i + 1][j + 1] += overflow;
                }
            }
        }
        return min(1.0, tower[query_row][query_glass]);
    }
};