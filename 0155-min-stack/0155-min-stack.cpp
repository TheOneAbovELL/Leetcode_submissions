class MinStack {
    vector<pair<int,int>> s;
public:
    MinStack() {}
    void push(int v) {
        if(s.empty()) s.push_back({v,v});
        else s.push_back({v,min(v,s.back().second)});
    }
    void pop() { s.pop_back(); }
    int top() { return s.back().first; }
    int getMin() { return s.back().second; }
};