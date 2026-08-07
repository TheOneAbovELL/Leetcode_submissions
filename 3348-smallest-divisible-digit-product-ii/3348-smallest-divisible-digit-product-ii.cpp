#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    string smallestNumber(string num, long long t) {
        long long rem = t;
        for (int d = 2; d <= 9; d++) {
            while (rem % d == 0)
                rem /= d;
        }
        if (rem > 1)
            return "-1";
        int n = num.size();
        vector<long long> requiredFactor(n + 1, 0);
        requiredFactor[0] = t;
        vector<char> digits(num.begin(), num.end());
        int firstZero = n - 1;
        for (int i = 0; i < n; i++) {
            if (digits[i] == '0') {
                firstZero = i;
                break;
            }
            requiredFactor[i + 1] =
                requiredFactor[i] / gcdll(requiredFactor[i], digits[i] - '0');
        }
        if (requiredFactor[n] == 1)
            return num;
        for (int i = firstZero; i >= 0; i--) {
            while (++digits[i] <= '9') {
                long long need = requiredFactor[i] /
                                 gcdll(requiredFactor[i], digits[i] - '0');
                int largest = 9;
                for (int j = n - 1; j > i; j--) {
                    while (largest > 1 && need % largest != 0)
                        largest--;
                    if (largest == 1) {
                        digits[j] = '1';
                        continue;
                    }
                    need /= largest;
                    digits[j] = char('0' + largest);
                }
                if (need == 1)
                    return string(digits.begin(), digits.end());
            }
            digits[i] = num[i];
        }
        string ans;
        rem = t;
        for (int d = 9; d >= 2; d--) {
            while (rem % d == 0) {
                ans.push_back(char('0' + d));
                rem /= d;
            }
        }
        while (ans.size() < n + 1)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};