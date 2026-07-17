class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<long long> freq(maxVal+1,0);
        for(int x:nums) freq[x]++;
        vector<long long> multipleFreq(maxVal+1,0);
        for(int g=1;g<=maxVal;g++){
            long long cnt=0;
            for(int mul=g;mul<=maxVal;mul+=g){
                cnt+=freq[mul];
            }
            multipleFreq[g]=cnt*(cnt-1)/2;
        }
        vector<long long> gcdFreq(maxVal+1,0);
        for(int g=maxVal;g>=1;g--){
            gcdFreq[g]=multipleFreq[g];
            for(int mul=2*g;mul<=maxVal;mul+=g){
                gcdFreq[g]-=gcdFreq[mul];
            }
        }
        vector<long long> pref(maxVal+1,0);
        for(int g=1;g<=maxVal;g++){
            pref[g]=pref[g-1]+gcdFreq[g];
        }
        vector<int> res;
        for(long long q:queries){
            int l=1,r=maxVal,ans=1;
            while(l<=r){
                int mid=(l+r)/2;
                if(pref[mid]>q){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};