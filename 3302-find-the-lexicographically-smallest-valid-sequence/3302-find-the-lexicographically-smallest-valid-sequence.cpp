class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> suffix(m + 1, -1);
        suffix[m] = n;
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            suffix[j] = ptr;
            if (ptr >= 0) ptr--;
        }
        vector<int> result;
        bool changed = false;
        int i = 0;
        for (int j = 0; j < m; ++j) {
            bool found = false;
            while (i < n) {
                if (word1[i] == word2[j]) {
                    if (changed) {
                        if (suffix[j + 1] > i) {
                            result.push_back(i);
                            i++;
                            found = true;
                            break;
                        }
                    } else {
                        result.push_back(i);
                        i++;
                        found = true;
                        break;
                    }
                } else if (!changed) {
                    if (suffix[j + 1] > i) {
                        changed = true;
                        result.push_back(i);
                        i++;
                        found = true;
                        break;
                    }
                }
                i++;
            }
            if (!found) return {};
        }
        return result;
    }
};