class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size(),ops=0;
        while(true){
            bool nonDec=true;
            for(int i=1;i<n;i++)if(nums[i]<nums[i-1]){nonDec=false;break;}
            if(nonDec)return ops;
            int minSum=INT_MAX,idx=-1;
            for(int i=0;i<n-1;i++){
                int s=nums[i]+nums[i+1];
                if(s<minSum){minSum=s;idx=i;}
            }
            vector<int>next;
            for(int i=0;i<n;i++){
                if(i==idx){next.push_back(minSum);i++;}
                else next.push_back(nums[i]);
            }
            nums=next;
            n=nums.size();
            ops++;
        } 
    }
};