class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int res=0;
        for(int i=0;i<n;i++){
            res+=(i/8)+1;
        }
        return res;
    }
};