class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for(int num:arr1){
            while(num>0){
                prefixes.insert(num);
                num/=10;
            }
        }
        int res=0;
        for(int num:arr2){
            while(num>0){
                if(prefixes.count(num)){
                    res=max(res,(int)to_string(num).size());
                    break;
                }
                num/=10;
            }
        }
        return res;
    }
};