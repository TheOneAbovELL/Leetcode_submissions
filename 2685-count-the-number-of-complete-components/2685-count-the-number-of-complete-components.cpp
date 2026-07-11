class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
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
                int sz=comp.size();
                bool complete=true;
                for(int u:comp){
                    if(adj[u].size()!=sz-1){
                        complete=false;
                        break;
                    }
                }
                if(complete) res++;
            }
        }
        return res;
    }
};