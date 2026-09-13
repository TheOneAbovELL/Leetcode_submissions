class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) a.push_back({i,j});
                if(img2[i][j]==1) b.push_back({i,j});
            }
        }
        unordered_map<int,int> mp;
        int res=0;
        for(auto& p:a){
            for(auto& q:b){
                int key=(p.first-q.first+100)*200+(p.second-q.second+100);
                mp[key]++;
                res=max(res,mp[key]);
            }
        }
        return res;
    }
};