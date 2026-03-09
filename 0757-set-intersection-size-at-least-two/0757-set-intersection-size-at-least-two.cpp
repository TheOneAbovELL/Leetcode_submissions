class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        
        int result = 0;
        int first = -1, second = -1;
        
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            if (start > second) {
                result += 2;
                first = end - 1;
                second = end;
            } else if (start > first) {
                result += 1;
                first = second;
                second = end;
            }
        }
        
        return result;
    }
};