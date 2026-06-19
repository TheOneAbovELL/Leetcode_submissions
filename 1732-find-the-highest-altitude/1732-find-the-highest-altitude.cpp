class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur=0,res=0;
        for(int x:gain){
            cur+=x;
            res=max(res,cur);
        }
        return res;
    }
};