class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        long long sum=0;
        for(int x:stones) sum+=x;
        long long res=sum;
        for(int i=stones.size()-2;i>=1;i--){
            sum-=stones[i+1];
            res=max(res,sum-res);
        }
        return res;
    }
};