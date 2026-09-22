class Solution {
    struct N { int p=1, c[5]={0}; };
    vector<N> t;
    int K;
    N mrg(N L, N R) {
        N r; r.p=(L.p*R.p)%K;
        for(int i=0;i<K;++i) r.c[i]=L.c[i];
        for(int i=0;i<K;++i) r.c[(L.p*i)%K]+=R.c[i];
        return r;
    }
    void bld(int i, int l, int r, vector<int>& a) {
        if(l==r){ t[i].p=a[l]%K; t[i].c[a[l]%K]=1; return; }
        int m=(l+r)/2;
        bld(2*i+1,l,m,a); bld(2*i+2,m+1,r,a);
        t[i]=mrg(t[2*i+1],t[2*i+2]);
    }
    void upd(int i, int l, int r, int x, int v) {
        if(l==r){
            t[i].p=v%K;
            for(int j=0;j<K;++j) t[i].c[j]=0;
            t[i].c[v%K]=1; return;
        }
        int m=(l+r)/2;
        if(x<=m) upd(2*i+1,l,m,x,v);
        else upd(2*i+2,m+1,r,x,v);
        t[i]=mrg(t[2*i+1],t[2*i+2]);
    }
    N qry(int i, int l, int r, int ql, int qr) {
        if(ql<=l&&r<=qr) return t[i];
        int m=(l+r)/2;
        if(qr<=m) return qry(2*i+1,l,m,ql,qr);
        if(ql>m) return qry(2*i+2,m+1,r,ql,qr);
        return mrg(qry(2*i+1,l,m,ql,qr),qry(2*i+2,m+1,r,ql,qr));
    }
public:
    vector<int> findXValue(vector<int>& a, int k, vector<vector<int>>& q) {
        int n=a.size(); K=k;
        t.assign(4*n,N());
        bld(0,0,n-1,a);
        vector<int> res;
        for(auto& x:q){
            upd(0,0,n-1,x[0],x[1]);
            res.push_back(qry(0,0,n-1,x[2],n-1).c[x[3]]);
        }
        return res;
    }
    vector<int> resultArray(vector<int>& a, int k, vector<vector<int>>& q) { return findXValue(a,k,q); }
};