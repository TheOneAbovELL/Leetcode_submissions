class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> sa(n),rk(nums),tmp(n),lcp(n);
        iota(sa.begin(),sa.end(),0);
        for(int k=1;;k<<=1){
            auto cmp=[&](int a,int b){
                if(rk[a]!=rk[b]) return rk[a]<rk[b];
                int ra=a+k<n?rk[a+k]:-1,rb=b+k<n?rk[b+k]:-1;
                return ra<rb;
            };
            sort(sa.begin(),sa.end(),cmp);
            tmp[sa[0]]=0;
            for(int i=1;i<n;++i) tmp[sa[i]]=tmp[sa[i-1]]+cmp(sa[i-1],sa[i]);
            rk=tmp;
            if(rk[sa[n-1]]==n-1) break;
        }
        for(int i=0,k=0;i<n;++i){
            if(rk[i]==n-1){k=0;continue;}
            int j=sa[rk[i]+1];
            while(i+k<n&&j+k<n&&nums[i+k]==nums[j+k]) k++;
            lcp[rk[i]]=k;
            if(k) k--;
        }
        int ans=n;
        for(int i=0;i<n;++i){
            int m=max(i?lcp[i-1]:0,lcp[i]);
            if(n-sa[i]>m) ans=min(ans,m+1);
        }
        return ans;
    }
};