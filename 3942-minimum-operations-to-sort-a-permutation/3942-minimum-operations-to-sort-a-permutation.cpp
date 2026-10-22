class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), idx = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                idx = i;
                break;
            }
        }
        bool asc = true, desc = true;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != (i - idx + n) % n) asc = false;
            if(nums[i] != (idx - i + n) % n) desc = false;
        }
        int ans = 2e9;
        if(asc) ans = min({ans, idx, idx == 0 ? 0 : n - idx + 2});
        if(desc) {
            int k = (n - 1 - idx) % n;
            ans = min({ans, k + 1, (n - k) % n + 1});
        }
        return ans == 2e9 ? -1 : ans;
    }
};