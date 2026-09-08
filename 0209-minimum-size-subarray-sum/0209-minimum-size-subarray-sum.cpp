class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int numcount=0;
        int mincount=INT_MAX;
        while(l<=r && r<nums.size()){
            sum+=nums[r];
            numcount++;
            r++;
            while(sum>=target){
                mincount=min(numcount,mincount);
                sum-=nums[l];
                l++;
                numcount--;
            }
        }
        if(mincount==INT_MAX)
            return 0;
        return mincount;
    }
};