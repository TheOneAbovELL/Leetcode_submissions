class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int a,int b){
            int ca=__builtin_popcount(a),cb=__builtin_popcount(b);
            return ca==cb?a<b:ca<cb;
        });
        return arr;
    }
};