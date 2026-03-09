class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> validCoupons;
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        regex pattern("^[a-zA-Z0-9_]+$");
        for (int i = 0; i < code.size(); ++i) {
            if (!isActive[i]) continue;
            if (code[i].empty()) continue;
            if (order.find(businessLine[i]) == order.end()) continue;
            if (!regex_match(code[i], pattern)) continue;
            
            validCoupons.emplace_back(businessLine[i], code[i]);
        }
        sort(validCoupons.begin(), validCoupons.end(),
            [&order](const pair<string, string>& a, const pair<string, string>& b) {
                if (order.at(a.first) != order.at(b.first)) {
                    return order.at(a.first) < order.at(b.first);
                }
                return a.second < b.second;
            });
        vector<string> result;
        for (const auto& p : validCoupons) {
            result.push_back(p.second);
        }
        return result;
    }
};