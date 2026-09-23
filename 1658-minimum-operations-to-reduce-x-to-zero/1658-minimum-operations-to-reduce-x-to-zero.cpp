class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int s=0,n=a.size(),c=0,m=-1,l=0;
        for(int v:a) s+=v;
        int t=s-x;
        if(t<0) return -1;
        for(int r=0;r<n;++r){
            c+=a[r];
            while(c>t) c-=a[l++];
            if(c==t) m=max(m,r-l+1);
        }
        return m==-1?-1:n-m;
    }
};