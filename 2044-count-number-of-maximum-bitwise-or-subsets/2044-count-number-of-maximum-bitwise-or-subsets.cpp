class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        int n = nums.size();
        int count = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int currentOr = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }
            if (currentOr == maxOr) {
                count++;
            }
        }
        return count;
    }
};