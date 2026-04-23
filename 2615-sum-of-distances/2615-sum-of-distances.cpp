class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> pos;
        for(int i=0;i<n;i++) pos[nums[i]].push_back(i);
        vector<long long> res(n,0);
        for(auto& [val,indices]:pos){
            int m=indices.size();
            if(m==1) continue;
            vector<long long> prefix(m+1,0);
            for(int i=0;i<m;i++) prefix[i+1]=prefix[i]+indices[i];
            for(int i=0;i<m;i++){
                long long left=1LL*indices[i]*i-prefix[i];
                long long right=(prefix[m]-prefix[i+1])-1LL*indices[i]*(m-i-1);
                res[indices[i]]=left+right;
            }
        }
        return res;
    }
};