class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int m=2e9,o=0;
        for(int x:a){
            if(x<m) m=x;
            if(x&1) o=1;
        }
        return (m&1)||!o;
    }
};