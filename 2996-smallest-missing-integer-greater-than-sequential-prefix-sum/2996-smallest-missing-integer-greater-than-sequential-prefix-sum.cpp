class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int presum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                presum+=nums[i];
            }
            else{
                break;
            }
        }
        std::unordered_set<int> seen(nums.begin(), nums.end());
        while(seen.count(presum)){
            presum++;
        }
        return presum;
    }
};