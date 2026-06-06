class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        int leftSum=0,rightSum=0;
        for(int x:nums) rightSum+=x;
        for(int i=0;i<n;i++){
            rightSum-=nums[i];
            res[i]=abs(leftSum-rightSum);
            leftSum+=nums[i];
        }
        return res;
    }
};