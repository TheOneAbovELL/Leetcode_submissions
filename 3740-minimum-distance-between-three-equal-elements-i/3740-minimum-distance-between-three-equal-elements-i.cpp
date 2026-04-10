class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]!=nums[j]) continue;
                for(int k=j+1;k<n;k++){
                    if(nums[i]!=nums[k]) continue;
                    int dist=abs(i-j)+abs(j-k)+abs(k-i);
                    res=min(res,dist);
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};