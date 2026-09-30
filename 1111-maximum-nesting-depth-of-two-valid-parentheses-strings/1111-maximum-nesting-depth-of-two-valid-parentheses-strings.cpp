class Solution {
public:
    vector< int > maxDepthAfterSplit(string seq) {
        vector< int > r(seq.size());
        int d=0;
        for(int i=0;i<seq.size();++i){
            if(seq[i]=='(') r[i]=d++%2;
            else r[i]=--d%2;
        }
        return r;
    }
};