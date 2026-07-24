class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> two;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                two.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> res;
        for(int x:two){
            for(int y:nums){
                res.insert(x^y);
            }
        }
        return res.size();
    }
};