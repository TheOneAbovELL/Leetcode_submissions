class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        function<void(int)> dfs=[&](int idx){
            if(idx==nums.size()){
                res.push_back(nums);
                return;
            }
            for(int i=idx;i<nums.size();i++){
                swap(nums[idx],nums[i]);
                dfs(idx+1);
                swap(nums[idx],nums[i]);
            }
        };
        dfs(0);
        return res;
    }
};