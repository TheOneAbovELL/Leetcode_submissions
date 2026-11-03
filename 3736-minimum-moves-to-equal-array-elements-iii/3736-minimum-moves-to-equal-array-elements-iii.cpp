class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int x:nums) ans+=m-x;
        return ans;
    }
};