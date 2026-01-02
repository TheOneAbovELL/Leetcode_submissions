class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
    for(int h: happiness) pq.push(h);
    long long sum=0;
    int dec=0;
    while(k-- && !pq.empty()){
        int top=pq.top();
        pq.pop();
        sum+=max(top-dec,0);
        dec++;
    }
    return sum;
    }
};