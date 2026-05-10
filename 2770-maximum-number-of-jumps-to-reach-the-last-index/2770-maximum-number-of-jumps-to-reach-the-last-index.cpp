class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> jumps(n,-1);
        jumps[0]=0;
        for(int i=0;i<n;i++){
            if(jumps[i]==-1) continue;
            for(int j=i+1;j<n;j++){
                long long diff=(long long)nums[j]-nums[i];
                if(diff>=-target&&diff<=target){
                    jumps[j]=max(jumps[j],jumps[i]+1);
                }
            }
        }
        return jumps[n-1];
    }
};