class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& n, int l) {
        int s=n.size();
        vector<pair<int,int>> p(s);
        for(int i=0;i<s;i++) p[i]={n[i],i};
        sort(p.begin(),p.end());
        vector<int> a(s);
        int i=0;
        while(i<s){
            int j=i+1;
            while(j<s&&p[j].first-p[j-1].first<=l) j++;
            vector<int> idx;
            for(int k=i;k<j;k++) idx.push_back(p[k].second);
            sort(idx.begin(),idx.end());
            for(int k=i;k<j;k++) a[idx[k-i]]=p[k].first;
            i=j;
        }
        return a;
    }
};