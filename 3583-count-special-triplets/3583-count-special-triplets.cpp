class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> left_count;
        unordered_map<int, int> right_count;
        long long result = 0;
        
        for (int num : nums) {
            right_count[num]++;
        }
        
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            int num = nums[j];
            right_count[num]--;
            
            long long left_val = left_count[num * 2];
            long long right_val = right_count[num * 2];
            
            result = (result + left_val * right_val) % MOD;
            
            left_count[num]++;
        }
        
        return result;
    }
};