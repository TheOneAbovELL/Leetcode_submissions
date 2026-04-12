class Solution {
public:
    int dist(char a, char b) {
        if (a == ' ') return 0;
        int x1 = (a - 'A') / 6, y1 = (a - 'A') % 6;
        int x2 = (b - 'A') / 6, y2 = (b - 'A') % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int minimumDistance(string word) {
        int n = word.size();
        unordered_map<string, int> memo;
        
        function<int(int, char, char)> dfs = [&](int idx, char f1, char f2) {
            if (idx == n) return 0;
            string key = to_string(idx) + "," + f1 + "," + f2;
            if (memo.count(key)) return memo[key];
            
            char cur = word[idx];
            int use1 = dist(f1, cur) + dfs(idx + 1, cur, f2);
            int use2 = dist(f2, cur) + dfs(idx + 1, f1, cur);
            
            return memo[key] = min(use1, use2);
        };
        
        return dfs(0, ' ', ' ');
    }
};