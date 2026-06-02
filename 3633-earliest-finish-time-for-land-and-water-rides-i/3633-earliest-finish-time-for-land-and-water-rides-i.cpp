class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size(), m=waterStartTime.size();
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int startLand = landStartTime[i];
                int endLand = startLand + landDuration[i];
                int startWater = max(waterStartTime[j], endLand);
                int endWater = startWater + waterDuration[j];
                res = min(res, endWater);
                
                int startWater2 = waterStartTime[j];
                int endWater2 = startWater2 + waterDuration[j];
                int startLand2 = max(landStartTime[i], endWater2);
                int endLand2 = startLand2 + landDuration[i];
                res = min(res, endLand2);
            }
        }
        return res;
    }
};