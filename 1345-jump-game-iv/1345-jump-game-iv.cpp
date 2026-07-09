class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front();q.pop();
                if(i==n-1) return steps;
                if(i+1<n&&!vis[i+1]){
                    vis[i+1]=true;
                    q.push(i+1);
                }
                if(i-1>=0&&!vis[i-1]){
                    vis[i-1]=true;
                    q.push(i-1);
                }
                for(int j:mp[arr[i]]){
                    if(!vis[j]){
                        vis[j]=true;
                        q.push(j);
                    }
                }
                mp[arr[i]].clear();
            }
            steps++;
        }
        return -1;
    }
};