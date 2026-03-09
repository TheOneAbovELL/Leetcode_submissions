class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        while (i < n && nums[i] != 1) {
            i++;
        }
        int prev = i;
        i++; 
        while (i < n) {
            if (nums[i] == 1) {
                if (i - prev - 1 < k) {
                    return false;
                }
                prev = i;
            }
            i++;
        }
        return true;        
    }
};