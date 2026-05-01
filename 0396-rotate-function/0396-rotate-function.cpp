class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long long sum=0,F=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            F+=i*nums[i];
        }
        long long res=F;
        for(int i=n-1;i>0;i--){
            F+=sum-(long long)n*nums[i];
            res=max(res,F);
        }
        return res;
    }
};