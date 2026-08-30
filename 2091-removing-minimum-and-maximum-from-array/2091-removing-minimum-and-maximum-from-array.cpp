class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int i=0,j=0,n=a.size();
        for(int k=1;k<n;k++){
            if(a[k]<a[i]) i=k;
            if(a[k]>a[j]) j=k;
        }
        if(i>j) swap(i,j);
        return min({j+1,n-i,i+1+n-j});
    }
};