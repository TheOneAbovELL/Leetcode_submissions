class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0,right=0,any=0;
        for(char c:moves){
            if(c=='L') left++;
            else if(c=='R') right++;
            else any++;
        }
        return max(abs(left-right)+any,abs(left-right-any));
    }
};