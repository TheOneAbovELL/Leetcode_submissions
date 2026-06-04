class Solution {
public:
    int waviness(int num) {
        if(num<100) return 0;
        string s=to_string(num);
        int res=0;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]>s[i-1]&&s[i]>s[i+1]) res++;
            else if(s[i]<s[i-1]&&s[i]<s[i+1]) res++;
        }
        return res;
    }
    int totalWaviness(int num1, int num2) {
        int sum=0;
        for(int i=num1;i<=num2;i++) sum+=waviness(i);
        return sum;
    }
};