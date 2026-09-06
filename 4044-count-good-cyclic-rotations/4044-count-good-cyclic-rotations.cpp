class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long int leftsum=accumulate(nums.begin(),nums.begin()+(n/2),0LL);
        long long int rightsum=accumulate(nums.begin()+(n/2),nums.end(),0LL);
        int templ=0;
        int tempr=n-1;
        int tempm=n/2;
        int ans=0;
        while(templ<n){
            leftsum-=(long long)nums[templ];
            rightsum-=(long long)nums[tempm];
            leftsum+=(long long)nums[tempm];
            rightsum+=(long long)nums[templ];
            if(leftsum>rightsum)
                ans++;
            templ++;
            tempm++;
            if(tempm==n)
                tempm%=n;
        }
        return ans;
    }
};