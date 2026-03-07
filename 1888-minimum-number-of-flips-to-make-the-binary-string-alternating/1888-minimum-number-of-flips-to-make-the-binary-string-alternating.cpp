class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string ss = s + s;
        
        vector<int> diff0(2*n, 0);
        vector<int> diff1(2*n, 0);
        
        for (int i = 0; i < 2*n; i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            diff0[i] = (ss[i] != expected0) ? 1 : 0;
            
            char expected1 = (i % 2 == 0) ? '1' : '0';
            diff1[i] = (ss[i] != expected1) ? 1 : 0;
        }
        
        vector<int> prefix0(2*n + 1, 0);
        vector<int> prefix1(2*n + 1, 0);
        
        for (int i = 0; i < 2*n; i++) {
            prefix0[i + 1] = prefix0[i] + diff0[i];
            prefix1[i + 1] = prefix1[i] + diff1[i];
        }
        
        int minFlips = n;
        
        for (int start = 0; start < n; start++) {
            int mismatches0 = prefix0[start + n] - prefix0[start];
            int mismatches1 = prefix1[start + n] - prefix1[start];
            minFlips = min(minFlips, min(mismatches0, mismatches1));
        }
        
        return minFlips;
    }
};