class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> busy;
        for(int i = 0; i < servers.size(); ++i) free.push({servers[i], i});
        
        vector<int> ans(tasks.size());
        long long t = 0;
        for(int j = 0; j < tasks.size(); ++j) {
            t = max(t, (long long)j);
            if(free.empty()) t = busy.top().first;
            while(!busy.empty() && busy.top().first <= t) {
                free.push(busy.top().second);
                busy.pop();
            }
            auto [w, i] = free.top();
            free.pop();
            ans[j] = i;
            busy.push({t + tasks[j], {w, i}});
        }
        return ans;
    }
};