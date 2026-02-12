class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (freq[idx] == 0) distinct++;
                freq[idx]++;
                
                int k = freq[idx];
                bool balanced = true;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0 && freq[c] != k) {
                        balanced = false;
                        break;
                    }
                }
                if (balanced) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};