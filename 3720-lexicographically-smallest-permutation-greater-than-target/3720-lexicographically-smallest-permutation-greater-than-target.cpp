class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        string ans = "", pre = "";
        for (int i = 0; i < t.size(); i++) {
            for (int c = t[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string temp = pre + (char)(c + 'a');
                    cnt[c]--; 
                    for (int j = 0; j < 26; j++) {
                        temp.append(cnt[j], j + 'a');
                    }
                    ans = temp; 
                    cnt[c]++;   
                    break;      
                }
            }
            if (cnt[t[i] - 'a'] > 0) {
                pre += t[i];
                cnt[t[i] - 'a']--;
            } else {
                break; 
            }
        }
        return ans;
    }
};