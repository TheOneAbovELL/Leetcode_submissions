class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if(target<0) return;
        if(target==0){
            result.push_back(current);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            current.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i,current,result);
            current.pop_back();
        }
    }
};