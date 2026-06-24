class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int m=num1.size(),n=num2.size();
        vector<int> res(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=mul+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
        string ans;
        int i=0;
        while(i<res.size()&&res[i]==0) i++;
        while(i<res.size()) ans+=to_string(res[i++]);
        return ans;
    }
};