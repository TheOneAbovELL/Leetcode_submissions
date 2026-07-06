class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        });
        int res=0,cur=0;
        for(auto& in:intervals){
            if(in[1]>cur){
                res++;
                cur=in[1];
            }
        }
        return res;
    }
};