class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n), radj(n);
        for(auto& inv:invocations){
            adj[inv[0]].push_back(inv[1]);
            radj[inv[1]].push_back(inv[0]);
        }
        vector<bool> susp(n,false);
        queue<int> q;
        q.push(k);
        susp[k]=true;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:adj[u]){
                if(!susp[v]){
                    susp[v]=true;
                    q.push(v);
                }
            }
        }
        vector<int> res;
        bool canRemove=true;
        for(int i=0;i<n;i++){
            if(!susp[i]){
                for(int v:adj[i]){
                    if(susp[v]){
                        canRemove=false;
                        break;
                    }
                }
                if(!canRemove) break;
            }
        }
        if(!canRemove){
            for(int i=0;i<n;i++) res.push_back(i);
            return res;
        }
        for(int i=0;i<n;i++){
            if(!susp[i]) res.push_back(i);
        }
        return res;
    }
};