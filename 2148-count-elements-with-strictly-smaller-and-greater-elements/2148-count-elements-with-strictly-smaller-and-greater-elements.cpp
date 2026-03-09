class Solution {
public:
    int countElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int count = 0;

        for (int num : nums) {
            if (num > minVal && num < maxVal) {
                count++;
            }
        }
        return count;
    }
};
