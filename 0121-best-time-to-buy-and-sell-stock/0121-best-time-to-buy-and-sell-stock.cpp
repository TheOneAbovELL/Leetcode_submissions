class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX,maxp=0;
        for(int price:prices){
            if(price<min) min=price;
            else maxp=max(maxp,price-min);
        }
        return maxp;
    }
};