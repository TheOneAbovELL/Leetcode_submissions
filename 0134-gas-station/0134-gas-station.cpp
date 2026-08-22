class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int t=0,c=0,s=0;
        for(int i=0;i<gas.size();i++){
            t+=gas[i]-cost[i];
            c+=gas[i]-cost[i];
            if(c<0){
                s=i+1;
                c=0;
            }
        }
        return t>=0?s:-1;
    }
};