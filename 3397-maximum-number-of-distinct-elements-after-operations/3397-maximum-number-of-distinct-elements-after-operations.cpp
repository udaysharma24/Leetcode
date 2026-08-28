class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int prev=-1e9;
        int ans=0;
        for(int i=0; i<n; i++){
            int l=max(prev+1,nums[i]-k);
            if(l<=nums[i]+k){
                prev=l;
                ans++;
            }
        }
        return ans;
    }
};