class Solution {
    using ll = long long;
public:
    int numOfSubarrays(vector<int>& arr) {
        ll odd=0,even=1,sum=0,ans=0,mod=1e9+7;
        for(int x:arr){
            sum+=x;
            if(sum%2){ans=(ans+even)%mod;odd++;}
            else{ans=(ans+odd)%mod;even++;}
        }
        return ans;
    }
};