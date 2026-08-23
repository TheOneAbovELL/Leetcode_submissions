class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(),bank.end());
        if(!dict.count(endGene)) return -1;
        queue<string> q;
        q.push(startGene);
        unordered_set<string> vis;
        vis.insert(startGene);
        int steps=0;
        string genes="ACGT";
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string cur=q.front();q.pop();
                if(cur==endGene) return steps;
                for(int i=0;i<8;i++){
                    char orig=cur[i];
                    for(char c:genes){
                        if(c==orig) continue;
                        cur[i]=c;
                        if(dict.count(cur)&&!vis.count(cur)){
                            vis.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[i]=orig;
                }
            }
            steps++;
        }
        return -1;
    }
};