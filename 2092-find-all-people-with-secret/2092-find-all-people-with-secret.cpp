class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else if (rank[rx] > rank[ry]) parent[ry] = rx;
        else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        UnionFind uf(n);
        uf.unite(0, firstPerson);
        
        int m = meetings.size();
        for (int i = 0; i < m; ) {
            int time = meetings[i][2];
            vector<pair<int, int>> edges;
            set<int> people;
            
            while (i < m && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                edges.emplace_back(x, y);
                people.insert(x);
                people.insert(y);
                i++;
            }
            
            for (auto& [x, y] : edges) {
                uf.unite(x, y);
            }
            
            for (int person : people) {
                if (!uf.connected(person, 0)) {
                    uf.parent[person] = person;
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (uf.connected(i, 0)) {
                result.push_back(i);
            }
        }
        return result;
    }
};