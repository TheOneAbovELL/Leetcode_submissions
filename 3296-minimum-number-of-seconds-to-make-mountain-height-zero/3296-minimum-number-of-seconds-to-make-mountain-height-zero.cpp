class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left=1,right=1e18;
        while(left<right){
            long long mid=left+(right-left)/2;
            long long total=0;
            for(int t:workerTimes){
                long long low=1,high=mountainHeight;
                while(low<=high){
                    long long m=low+(high-low)/2;
                    if(m*(m+1)/2*t<=mid){
                        low=m+1;
                    }else{
                        high=m-1;
                    }
                }
                total+=high;
                if(total>=mountainHeight)break;
            }
            if(total>=mountainHeight){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};