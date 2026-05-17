class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int i=q.front();q.pop();
            if(arr[i]==0) return true;
            if(i+arr[i]<n&&!vis[i+arr[i]]){
                vis[i+arr[i]]=true;
                q.push(i+arr[i]);
            }
            if(i-arr[i]>=0&&!vis[i-arr[i]]){
                vis[i-arr[i]]=true;
                q.push(i-arr[i]);
            }
        }
        return false;
    }
};