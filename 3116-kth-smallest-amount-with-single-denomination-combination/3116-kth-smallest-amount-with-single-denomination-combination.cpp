class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<pair<long long, int>> subsets;
        for (int mask= 1; mask<(1<<n); ++mask) {
            long long currentlcm = 1;
            int bits=0;
            for (int i=0; i<n; ++i) {
                if ((mask>>i) & 1) {
                    currentlcm=lcm(currentlcm, (long long)coins[i]);
                    bits++;
                }
            }
            int sign=(bits%2 == 1) ? 1:-1;
            subsets.push_back({currentlcm, sign});
        }
        
        long long low = 1;
        long long high=(long long)k**min_element(coins.begin(), coins.end());
        long long ans=high;
        while (low<=high){
            long long mid=low+(high-low)/2;
            long long count=0;
            for (auto& p:subsets) {
                count+=p.second*(mid/p.first);
            }
            if (count >= k) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};