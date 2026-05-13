class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> diff(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int a=nums[i],b=nums[n-1-i];
            int low=min(a,b)+1;
            int high=max(a,b)+limit;
            diff[2]+=2;
            diff[low]--;
            diff[a+b]--;
            diff[a+b+1]++;
            diff[high+1]++;
        }
        int res=n,curr=0;
        for(int i=2;i<=2*limit;i++){
            curr+=diff[i];
            res=min(res,curr);
        }
        return res;
    }
};