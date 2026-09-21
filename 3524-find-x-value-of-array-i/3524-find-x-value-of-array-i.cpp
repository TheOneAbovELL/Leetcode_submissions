class Solution {
public:
    vector<long long> resultArray(vector<int>& a, int k) {
        vector<long long> r(k,0), d(k,0);
        for(int x:a){
            vector<long long> t(k,0);
            int m=x%k; t[m]=1;
            for(int i=0;i<k;i++) t[(i*m)%k]+=d[i];
            for(int i=0;i<k;i++) r[i]+=t[i];
            d=t;
        }
        return r;
    }
};