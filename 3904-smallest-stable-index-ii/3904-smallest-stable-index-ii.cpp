class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minn(n,INT_MAX);
        minn[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            minn[i]=min(nums[i],minn[i+1]);
        }
        int mx=-1;
        int mn=INT_MAX;
        for(int i=0; i<n; i++){
            mx=max(nums[i],mx);
            mn=minn[i];
            if(mx-mn<=k)
                return i;
        }
        return -1;
    }
};