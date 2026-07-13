class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int len=1;len<=9;len++){
            for(int start=1;start+len-1<=9;start++){
                int num=0;
                for(int i=0;i<len;i++){
                    num=num*10+(start+i);
                }
                if(num>=low&&num<=high) res.push_back(num);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};