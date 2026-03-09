class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (int a : apple) total += a;
        sort(capacity.rbegin(), capacity.rend());
        int used = 0;
        int sum = 0;
        for (int c : capacity) {
            sum += c;
            used++;
            if (sum >= total) break;
        }
        return used;
    }
};