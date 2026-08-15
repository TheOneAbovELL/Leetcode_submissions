class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0,z=0,n=nums.size();
        for(int num:nums){
            x^=num;
            if(num==0) z++;
        }
        if(x!=0) return n;
        if(z==n) return 0;
        return n-1;
    }
};