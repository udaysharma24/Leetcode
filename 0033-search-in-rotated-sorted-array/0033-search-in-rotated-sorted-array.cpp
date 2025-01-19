class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high)
        {
            if(nums[low]==target)
                return low;
            else if(nums[high]==target)
                return high;
            else if(nums[low]<nums[mid])
            {
                if(binary_search(nums.begin()+low,nums.begin()+mid+1,target))
                    return (lower_bound(nums.begin()+low,nums.begin()+mid+1,target)-nums.begin());
                else
                {
                    low=mid+1;
                    mid=(low+high)/2;
                }
            }
            else
            {
                if(binary_search(nums.begin()+mid,nums.begin()+high+1,target))
                    return (lower_bound(nums.begin()+mid, nums.begin()+high+1,target)-nums.begin());
                else
                {
                    high=mid-1;
                    mid=(low+high)/2;
                }
            }
        }
        return -1;
    }
};