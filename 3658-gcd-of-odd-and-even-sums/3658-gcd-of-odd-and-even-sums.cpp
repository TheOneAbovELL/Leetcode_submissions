class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = n * n;
        long long sumEven = n * (n + 1);
        return __gcd((int)sumOdd, (int)sumEven);
    }
};