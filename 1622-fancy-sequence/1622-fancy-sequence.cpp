class Fancy {
private:
    vector<long long>seq;
    long long add=0,mul=1;
    const int MOD=1e9+7;
public:
    Fancy(){}
    
    void append(int val) {
        val=(val-add+MOD)%MOD;
        val=(val*modInv(mul))%MOD;
        seq.push_back(val);
    }
    
    void addAll(int inc) {
        add=(add+inc)%MOD;
    }
    
    void multAll(int m) {
        mul=(mul*m)%MOD;
        add=(add*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size())return -1;
        long long res=(seq[idx]*mul+add)%MOD;
        return res;
    }
    
    long long modInv(long long x){
        long long res=1,exp=MOD-2;
        while(exp){
            if(exp&1)res=(res*x)%MOD;
            x=(x*x)%MOD;
            exp>>=1;
        }
        return res;
    }
};