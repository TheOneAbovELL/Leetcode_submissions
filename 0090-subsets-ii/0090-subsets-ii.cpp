class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> dfs=[&](int idx){
            res.push_back(cur);
            for(int i=idx;i<nums.size();i++){
                if(i>idx&&nums[i]==nums[i-1]) continue;
                cur.push_back(nums[i]);
                dfs(i+1);
                cur.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};