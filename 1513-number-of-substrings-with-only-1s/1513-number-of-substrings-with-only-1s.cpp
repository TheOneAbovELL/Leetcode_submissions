class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long count = 0;
        long long ans = 0;
        for (char ch : s) {
            if (ch == '1') {
                count++;
            } else {
                ans = (ans + (count * (count + 1)) / 2) % MOD;
                count = 0;
            }
        }
        ans = (ans + (count * (count + 1)) / 2) % MOD;
        return ans;
    }
};