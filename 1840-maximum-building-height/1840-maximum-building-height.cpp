class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<pair<int,int>> rest;
        rest.push_back({1,0});
        for(auto& r:restrictions) rest.push_back({r[0],r[1]});
        sort(rest.begin(),rest.end());
        for(int i=1;i<rest.size();i++){
            int dist=rest[i].first-rest[i-1].first;
            rest[i].second=min(rest[i].second,rest[i-1].second+dist);
        }
        for(int i=rest.size()-2;i>=0;i--){
            int dist=rest[i+1].first-rest[i].first;
            rest[i].second=min(rest[i].second,rest[i+1].second+dist);
        }
        int res=0;
        for(int i=0;i<rest.size()-1;i++){
            int dist=rest[i+1].first-rest[i].first;
            int maxH=(dist+rest[i].second+rest[i+1].second)/2;
            res=max(res,maxH);
        }
        int last=rest.back().first;
        res=max(res,rest.back().second+(n-last));
        return res;
    }
};