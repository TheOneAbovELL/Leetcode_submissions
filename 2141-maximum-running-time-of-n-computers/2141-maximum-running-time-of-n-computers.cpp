class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) total += b;
        long long left = 1, right = total / n;
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            long long sum = 0;
            for (int b : batteries) sum += min((long long)b, mid);
            if (sum >= mid * n) left = mid;
            else right = mid - 1;
        }      
        return left;
    }
};