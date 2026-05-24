class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        for(int p=1;p<n-2;p++){
            for(int q=p+1;q<n-1;q++){
                bool inc1=true,dec=true,inc2=true;
                for(int i=1;i<=p;i++) if(nums[i]<=nums[i-1]) inc1=false;
                for(int i=p+1;i<=q;i++) if(nums[i]>=nums[i-1]) dec=false;
                for(int i=q+1;i<n;i++) if(nums[i]<=nums[i-1]) inc2=false;
                if(inc1&&dec&&inc2) return true;
            }
        }
        return false;
    }
};