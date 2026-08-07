#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int e2[10] = {0,0,1,0,2,0,1,0,3,0};
    int e3[10] = {0,0,0,1,0,0,1,0,0,2};
    int e5[10] = {0,0,0,0,0,1,0,0,0,0};
    int e7[10] = {0,0,0,0,0,0,0,1,0,0};

    vector<vector<int>> dp;
    int Alim, Blim;

    inline bool feasible(int remA, int remB, int remC, int remD, int remainingPositions) {
        if (remA < 0) remA = 0;
        if (remB < 0) remB = 0;
        if (remC < 0) remC = 0;
        if (remD < 0) remD = 0;
        if (remA > Alim) remA = Alim;
        if (remB > Blim) remB = Blim;
        return dp[remA][remB] + remC + remD <= remainingPositions;
    }

    string fillSuffix(int curA, int curB, int curC, int curD, int count) {
        string s(count, '1');
        for (int i = 0; i < count; i++) {
            int remaining = count - 1 - i;
            for (int d = 1; d <= 9; d++) {
                int nA = max(0, curA - e2[d]);
                int nB = max(0, curB - e3[d]);
                int nC = max(0, curC - e5[d]);
                int nD = max(0, curD - e7[d]);
                if (feasible(nA, nB, nC, nD, remaining)) {
                    s[i] = char('0' + d);
                    curA = nA; curB = nB; curC = nC; curD = nD;
                    break;
                }
            }
        }
        return s;
    }

    string smallestNumber(string num, long long t) {
        long long tt = t;
        int A = 0, B = 0, C = 0, D = 0;
        while (tt % 2 == 0) { tt /= 2; A++; }
        while (tt % 3 == 0) { tt /= 3; B++; }
        while (tt % 5 == 0) { tt /= 5; C++; }
        while (tt % 7 == 0) { tt /= 7; D++; }
        if (tt != 1) return "-1";

        Alim = A; Blim = B;
        dp.assign(A + 1, vector<int>(B + 1, 0));
        for (int i = 0; i <= A; i++) {
            for (int j = 0; j <= B; j++) {
                if (i == 0 && j == 0) { dp[i][j] = 0; continue; }
                int best = INT_MAX;
                if (i > 0) best = min(best, dp[max(i - 3, 0)][j] + 1);
                if (j > 0) best = min(best, dp[i][max(j - 2, 0)] + 1);
                if (i > 0 || j > 0) best = min(best, dp[max(i - 1, 0)][max(j - 1, 0)] + 1);
                dp[i][j] = best;
            }
        }

        int M = dp[A][B] + C + D;

        int n = (int)num.size();
        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int dig = num[i] - '0';
            p2[i + 1] = p2[i] + e2[dig];
            p3[i + 1] = p3[i] + e3[dig];
            p5[i + 1] = p5[i] + e5[dig];
            p7[i + 1] = p7[i] + e7[dig];
        }

        int firstZero = n;
        for (int i = 0; i < n; i++) if (num[i] == '0') { firstZero = i; break; }

        if (firstZero == n) {
            int remA = max(0, A - p2[n]), remB = max(0, B - p3[n]);
            int remC = max(0, C - p5[n]), remD = max(0, D - p7[n]);
            if (remA == 0 && remB == 0 && remC == 0 && remD == 0) return num;
        }

        int limit = min(firstZero, n - 1);
        for (int pos = limit; pos >= 0; pos--) {
            int lower = num[pos] - '0';
            int base2 = p2[pos], base3 = p3[pos], base5 = p5[pos], base7 = p7[pos];
            int remainingPositions = n - 1 - pos;
            for (int d = lower + 1; d <= 9; d++) {
                int remA = max(0, A - base2 - e2[d]);
                int remB = max(0, B - base3 - e3[d]);
                int remC = max(0, C - base5 - e5[d]);
                int remD = max(0, D - base7 - e7[d]);
                if (feasible(remA, remB, remC, remD, remainingPositions)) {
                    string res = num.substr(0, pos);
                    res += char('0' + d);
                    res += fillSuffix(remA, remB, remC, remD, remainingPositions);
                    return res;
                }
            }
        }

        int L = max(n + 1, M);
        return fillSuffix(A, B, C, D, L);
    }
};