class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            int rem = num % 3;
            if(rem == 1 || rem == 2) {
                ans += 1;
            }
        }
        return ans;
    }
};