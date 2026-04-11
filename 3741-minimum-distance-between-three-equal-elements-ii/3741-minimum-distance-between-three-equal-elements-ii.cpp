class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        int res=INT_MAX;
        for(auto& [val,pos]:mp){
            if(pos.size()<3) continue;
            for(int i=0;i<pos.size()-2;i++){
                int dist=2*(pos[i+2]-pos[i]);
                res=min(res,dist);
            }
        }
        return res==INT_MAX?-1:res;
    }
};