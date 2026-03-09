class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineUntil(numberOfUsers, 0);
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if (t1 != t2) return t1 < t2;
            if (a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
            if (a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;
            return false; 
        });
        for (const auto& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);
            for (int i = 0; i < numberOfUsers; i++) {
                if (offlineUntil[i] <= timestamp) {
                    offlineUntil[i] = 0; 
                }
            }
            if (type == "OFFLINE") {
                int id = stoi(event[2]);
                offlineUntil[id] = timestamp + 60;
            } 
            else if (type == "MESSAGE") {
                string msg = event[2];
                if (msg == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                }
                else if (msg == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offlineUntil[i] == 0) {
                            mentions[i]++;
                        }
                    }
                }
                else {
                    istringstream iss(msg);
                    string token;
                    while (iss >> token) {
                        int id = stoi(token.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }
        return mentions;
    }
};