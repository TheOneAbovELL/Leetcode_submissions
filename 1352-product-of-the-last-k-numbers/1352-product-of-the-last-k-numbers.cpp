class ProductOfNumbers {
    vector<int> p={1};
public:
    ProductOfNumbers(){}
    void add(int num){
        if(!num) p={1};
        else p.push_back(p.back()*num);
    }
    int getProduct(int k){
        int n=p.size();
        return k>=n?0:p.back()/p[n-1-k];
    }
};