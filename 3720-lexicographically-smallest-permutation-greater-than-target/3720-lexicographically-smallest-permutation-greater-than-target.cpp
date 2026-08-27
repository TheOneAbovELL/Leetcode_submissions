class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string best_cand = "";
        string prefix = "";
        for (int i = 0; i < target.length(); i++) {
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (count[c] > 0) {
                    string cand = prefix;
                    cand += (char)(c + 'a');
                    
                    vector<int> temp = count;
                    temp[c]--;
                    for (int j = 0; j < 26; j++) {
                        if (temp[j] > 0) {
                            cand.append(temp[j], (char)(j + 'a'));
                        }
                    }
                    best_cand = cand;
                    break; 
                }
            }
            if (count[target[i] - 'a'] > 0) {
                count[target[i] - 'a']--;
                prefix += target[i];
            } else {
                break;
            }
        }
        return best_cand;
    }
};