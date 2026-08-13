class Solution {
private:
    struct Node {
        int max_len;
        int pref_len;
        int suff_len;
        char pref_char;
        char suff_char;
        int size;
    };
    vector<Node> tree;
    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;
        res.pref_len = left.pref_len;
        if (left.pref_len == left.size && left.pref_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }
        res.suff_len = right.suff_len;
        if (right.suff_len == right.size && right.suff_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }
        res.max_len = max({left.max_len, right.max_len, res.pref_len, res.suff_len});
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }
        
        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {1, 1, 1, c, c, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n + 1);
        build(1, 0, n - 1, s);
        
        vector<int> ans;
        ans.reserve(queryIndices.size());
        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].max_len); 
        }
        
        return ans;
    }
};