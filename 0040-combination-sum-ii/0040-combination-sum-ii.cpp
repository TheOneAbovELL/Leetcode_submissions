class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int,int)> dfs=[&](int start,int sum){
            if(sum==target){
                res.push_back(cur);
                return;
            }
            for(int i=start;i<candidates.size();i++){
                if(i>start&&candidates[i]==candidates[i-1]) continue;
                if(sum+candidates[i]>target) break;
                cur.push_back(candidates[i]);
                dfs(i+1,sum+candidates[i]);
                cur.pop_back();
            }
        };
        dfs(0,0);
        return res;
    }
};