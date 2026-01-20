class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int x:nums){
            int a=-1;
            for(int y=0;y<=x;y++){
                if((y|(y+1))==x){
                    a=y;break;
                }
            }
            res.push_back(a);
        }
        return res;
    }
};