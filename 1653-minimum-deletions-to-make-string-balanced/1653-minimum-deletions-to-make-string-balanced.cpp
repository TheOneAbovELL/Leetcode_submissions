class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> a(n+1,0),b(n+1,0);
        for(int i=0;i<n;i++){
            b[i+1]=b[i]+(s[i]=='b');
        }
        for(int i=n-1;i>=0;i--){
            a[i]=a[i+1]+(s[i]=='a');
        }
        int res=INT_MAX;
        for(int i=0;i<=n;i++){
            res=min(res,b[i]+a[i]);
        }
        return res;
    }
};