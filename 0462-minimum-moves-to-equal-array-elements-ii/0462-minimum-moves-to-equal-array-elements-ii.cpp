class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int m=nums[n/2];
        int ans=0;
        for(int x:nums) ans+=abs(x-m);
        return ans;
    }
};