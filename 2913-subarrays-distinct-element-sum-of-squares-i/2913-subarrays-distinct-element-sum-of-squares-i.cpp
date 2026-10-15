class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size(),r=0;
        for(int i=0;i<n;++i){
            bool c[100005]={0};
            int d=0;
            for(int j=i;j<n;++j){
                if(!c[nums[j]]){
                    c[nums[j]]=1;
                    d++;
                }
                r+=d*d;
            }
        }
        return r;
    }
};