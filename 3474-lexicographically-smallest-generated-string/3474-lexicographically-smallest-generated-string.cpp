class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int len = n + m - 1;
        vector<char> word(len, '.');
        
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    int pos = i + j;
                    if (word[pos] == '.') {
                        word[pos] = str2[j];
                    } else if (word[pos] != str2[j]) {
                        return "";
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool forced = true;
                for (int j = 0; j < m; j++) {
                    int pos = i + j;
                    if (word[pos] == '.') {
                        forced = false;
                        break;
                    }
                    if (word[pos] != str2[j]) {
                        forced = false;
                        break;
                    }
                }
                if (forced) return "";
            }
        }
        
        for (int i = 0; i < len; i++) {
            if (word[i] != '.') continue;
            
            for (char c = 'a'; c <= 'z'; c++) {
                bool valid = true;
                word[i] = c;
                
                for (int k = 0; k < n; k++) {
                    if (str1[k] == 'F') {
                        int start = k, end = k + m - 1;
                        if (i >= start && i <= end) {
                            bool equal = true;
                            for (int j = 0; j < m; j++) {
                                int pos = start + j;
                                if (word[pos] == '.') {
                                    equal = false;
                                    break;
                                }
                                if (word[pos] != str2[j]) {
                                    equal = false;
                                    break;
                                }
                            }
                            if (equal) {
                                valid = false;
                                break;
                            }
                        }
                    }
                }
                
                if (valid) break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) return "";
                }
            } else {
                bool equal = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) return "";
            }
        }
        
        return string(word.begin(), word.end());
    }
};