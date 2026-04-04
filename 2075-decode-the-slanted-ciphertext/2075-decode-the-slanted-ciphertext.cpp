class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        if (n % rows != 0) cols++;
        
        vector<vector<char>> mat(rows, vector<char>(cols, ' '));
        
        int idx = 0;
        for (int i = 0; i < rows && idx < n; i++) {
            for (int j = 0; j < cols && idx < n; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }
        
        string res;
        for (int startCol = 0; startCol < cols; startCol++) {
            int r = 0, c = startCol;
            while (r < rows && c < cols) {
                res += mat[r][c];
                r++;
                c++;
            }
        }
        
        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};