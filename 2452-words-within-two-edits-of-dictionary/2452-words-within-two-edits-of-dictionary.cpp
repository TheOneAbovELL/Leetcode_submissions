class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(string& q:queries){
            for(string& d:dictionary){
                int diff=0;
                for(int i=0;i<q.size();i++){
                    if(q[i]!=d[i]) diff++;
                }
                if(diff<=2){
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};