class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9LL) return "";
        int n=sum/9, r=sum%9, z=num-n-(r>0?1:0);
        string ans(n,'9');
        if(r>0) ans+=to_string(r);
        if(z>0) ans.append(z,'0');
        return ans;
    }
};
