class Solution {
public:
    int smallestIndex(vector<int>& a) {
        for(int i=0;i<a.size();++i){
            int s=0,v=a[i];
            while(v) s+=v%10,v/=10;
            if(s==i) return i;
        }
        return -1;
    }
};