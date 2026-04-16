class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>> pos;
        for(int i=0;i<n;i++) pos[nums[i]].push_back(i);
        vector<int> res;
        for(int q:queries){
            int val=nums[q];
            auto& v=pos[val];
            if(v.size()<2){
                res.push_back(-1);
                continue;
            }
            int idx=lower_bound(v.begin(),v.end(),q)-v.begin();
            int left=v[(idx-1+v.size())%v.size()];
            int right=v[(idx+1)%v.size()];
            int d1=min(abs(q-left),n-abs(q-left));
            int d2=min(abs(q-right),n-abs(q-right));
            res.push_back(min(d1,d2));
        }
        return res;
    }
};