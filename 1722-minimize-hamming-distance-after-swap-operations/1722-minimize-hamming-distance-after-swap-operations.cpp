class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<vector<int>> adj(n);
        for(auto& s:allowedSwaps){
            adj[s[0]].push_back(s[1]);
            adj[s[1]].push_back(s[0]);
        }
        vector<bool> vis(n,false);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> comp;
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int u=q.front();q.pop();
                    comp.push_back(u);
                    for(int v:adj[u]){
                        if(!vis[v]){
                            vis[v]=true;
                            q.push(v);
                        }
                    }
                }
                unordered_map<int,int> freq;
                for(int idx:comp) freq[source[idx]]++;
                for(int idx:comp){
                    if(freq[target[idx]]>0) freq[target[idx]]--;
                    else res++;
                }
            }
        }
        return res;
    }
};