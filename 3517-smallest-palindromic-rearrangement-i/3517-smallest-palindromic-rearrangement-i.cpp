class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        string half="";
        char middle=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) middle='a'+i;
            half+=string(freq[i]/2,'a'+i);
        }
        string rev=half;
        reverse(rev.begin(),rev.end());
        if(middle) return half+middle+rev;
        return half+rev;
    }
};