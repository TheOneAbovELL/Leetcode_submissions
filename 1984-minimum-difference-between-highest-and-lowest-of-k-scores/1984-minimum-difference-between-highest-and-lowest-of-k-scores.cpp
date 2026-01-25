class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        for(int i=0;i+k-1<nums.size();i++){
            res=min(res,nums[i+k-1]-nums[i]);
        }
        return res;
    }
};