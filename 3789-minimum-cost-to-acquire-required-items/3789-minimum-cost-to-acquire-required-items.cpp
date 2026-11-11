class Solution {
    using ll = long long;
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll c1=cost1,c2=cost2,cb=costBoth,n1=need1,n2=need2;
        ll mn=min(n1,n2),mx=max(n1,n2);
        return min({n1*c1+n2*c2, mn*cb+(n1-mn)*c1+(n2-mn)*c2, mx*cb});
    }
};