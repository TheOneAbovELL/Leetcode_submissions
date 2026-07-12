class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int> rank;
        int r=1;
        for(int x:sorted){
            if(!rank.count(x)) rank[x]=r++;
        }
        vector<int> res;
        for(int x:arr) res.push_back(rank[x]);
        return res;
    }
};