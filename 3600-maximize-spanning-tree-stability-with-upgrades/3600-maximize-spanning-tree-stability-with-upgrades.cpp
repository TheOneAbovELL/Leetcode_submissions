class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            int rx = find(x), ry = find(y);
            if (rx == ry) return false;
            if (rank[rx] < rank[ry]) parent[rx] = ry;
            else if (rank[rx] > rank[ry]) parent[ry] = rx;
            else {
                parent[ry] = rx;
                rank[rx]++;
            }
            return true;
        }
    };
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int maxStrength = 0;
        for (auto& e : edges) {
            maxStrength = max(maxStrength, e[2]);
        }
        int low = 1, high = maxStrength * 2, ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            DSU dsu(n);
            bool possible = true;
            
            for (auto& e : edges) {
                if (e[3] == 1) {
                    if (e[2] < mid) {
                        possible = false;
                        break;
                    }
                    if (!dsu.unite(e[0], e[1])) {
                        possible = false;
                        break;
                    }
                }
            }
            
            if (!possible) {
                high = mid - 1;
                continue;
            }
            
            vector<int> comp(n);
            for (int i = 0; i < n; i++) comp[dsu.find(i)] = 1;
            int comps = 0;
            for (int i = 0; i < n; i++) comps += comp[i];
            
            for (auto& e : edges) {
                if (e[3] == 0 && e[2] >= mid) {
                    if (dsu.unite(e[0], e[1])) comps--;
                }
            }
            
            int upgradesUsed = 0;
            for (auto& e : edges) {
                if (e[3] == 0 && e[2] < mid && 2*e[2] >= mid) {
                    if (comps == 1) break;
                    if (dsu.unite(e[0], e[1])) {
                        comps--;
                        upgradesUsed++;
                    }
                }
            }
            
            if (comps == 1 && upgradesUsed <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};