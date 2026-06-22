class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26,0);
        for(char c:text) count[c-'a']++;
        int b=count['b'-'a'];
        int a=count['a'-'a'];
        int l=count['l'-'a']/2;
        int o=count['o'-'a']/2;
        int n=count['n'-'a'];
        return min({b,a,l,o,n});
    }
};