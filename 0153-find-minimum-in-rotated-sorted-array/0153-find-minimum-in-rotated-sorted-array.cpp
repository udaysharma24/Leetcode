class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=INT_MAX;
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high)
        {
            if(nums[low]<=nums[mid])
            {
                mn=min(nums[low],mn);
                low=mid+1;
                mid=(low+high)/2;
            }
            else
            {
                mn=min(nums[mid],mn);
                high=mid-1;
                mid=(low+high)/2;
            }
        }
        return mn;
    }
};