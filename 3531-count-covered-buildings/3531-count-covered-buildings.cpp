class Solution{
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings){
        unordered_map<int, vector<int>> buildingsAtX, buildingsAtY;
        for(auto &b:buildings){
            buildingsAtX[b[0]].push_back(b[1]);
            buildingsAtY[b[1]].push_back(b[0]);
        }
        for(auto &p:buildingsAtX) sort(p.second.begin(), p.second.end());
        for(auto &p:buildingsAtY) sort(p.second.begin(), p.second.end());
        int covered=0;
        for(auto &b:buildings){
            int x=b[0], y=b[1];
            auto &row=buildingsAtX[x];
            auto &col=buildingsAtY[y];
            bool left=row.front()<y;
            bool right=row.back()>y;
            bool above=col.front()<x;
            bool below=col.back()>x;
            if(left&&right&&above&&below) covered++;
        }
        return covered;
    }
};
