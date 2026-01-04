class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            int div_cnt = 0;
            int div_sum = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    if (i * i == num) {
                        div_cnt += 1;
                        div_sum += i;
                    } else {
                        div_cnt += 2;
                        div_sum += i + num / i;
                    }
                }
                if (div_cnt > 4) break;
            }
            if (div_cnt == 4) total += div_sum;
        }
        return total;
    }
};