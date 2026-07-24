class Solution {
public:
    bool isNumber(string s) {
        int i=0,n=s.size();
        bool digit=false,dot=false,exp=false;
        if(i<n&&(s[i]=='+'||s[i]=='-')) i++;
        while(i<n&&isdigit(s[i])){
            digit=true;
            i++;
        }
        if(i<n&&s[i]=='.'){
            dot=true;
            i++;
            while(i<n&&isdigit(s[i])){
                digit=true;
                i++;
            }
        }
        if(i<n&&(s[i]=='e'||s[i]=='E')){
            if(!digit) return false;
            exp=true;
            i++;
            if(i<n&&(s[i]=='+'||s[i]=='-')) i++;
            bool expDigit=false;
            while(i<n&&isdigit(s[i])){
                expDigit=true;
                i++;
            }
            if(!expDigit) return false;
        }
        return i==n&&digit;
    }
};