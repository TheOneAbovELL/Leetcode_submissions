class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);       
        if (ones > 0) {
            return n - ones;
        }       
        int minOps = INT_MAX;       
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minOps = min(minOps, j - i + n - 1);
                    break;
                }
            }
        }       
        return minOps == INT_MAX ? -1 : minOps;
    }  
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};