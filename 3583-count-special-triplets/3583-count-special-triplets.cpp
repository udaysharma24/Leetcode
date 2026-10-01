class Solution {
public:
    int MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        long long int ans=0LL;
        int zero=0;
        int lzero=0;
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            um[nums[i]]++;
            if(nums[i]==0)
                zero++;
        }
        unordered_map<int,int> lum;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                ans+=((long long)lzero*(long long)(zero-lzero-1));
                lzero++;
                continue;
            }
            lum[nums[i]]++;
            if(lum[2*nums[i]]>0)
                ans+=(lum[2*nums[i]]*(um[2*nums[i]]-lum[2*nums[i]]));
        }
        return (ans%MOD);
    }
};