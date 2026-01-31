class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         int n = letters.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left < n ? letters[left] : letters[0];
    }
};