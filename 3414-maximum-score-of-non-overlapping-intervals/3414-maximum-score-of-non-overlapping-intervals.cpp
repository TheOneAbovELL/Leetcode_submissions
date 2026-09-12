class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        struct I { int l, r, w, id; };
        vector<I> a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(a.begin(), a.end(), [](const I& x, const I& y){
            if (x.l != y.l) return x.l < y.l;
            if (x.r != y.r) return x.r < y.r;
            return x.id < y.id;
        });
        
        struct S {
            long long w = 0;
            vector<int> v;
        };
        vector<vector<S>> dp(n + 1, vector<S>(5));
        
        for(int i = n - 1; i >= 0; --i) {
            int nxt = n, low = i + 1, high = n - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(a[mid].l > a[i].r) { 
                    nxt = mid; 
                    high = mid - 1; 
                } else {
                    low = mid + 1;
                }
            }
            
            for(int k = 1; k <= 4; ++k) {
                long long w_inc = a[i].w + dp[nxt][k - 1].w;
                vector<int> v_inc = dp[nxt][k - 1].v;
                v_inc.push_back(a[i].id);
                sort(v_inc.begin(), v_inc.end());
                
                if(w_inc > dp[i + 1][k].w || (w_inc == dp[i + 1][k].w && v_inc < dp[i + 1][k].v)) {
                    dp[i][k] = {w_inc, v_inc};
                } else {
                    dp[i][k] = dp[i + 1][k];
                }
            }
        }
        return dp[0][4].v;
    }
};