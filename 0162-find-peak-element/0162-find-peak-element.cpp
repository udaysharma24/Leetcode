class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        else if(nums[0]>nums[1])
            return 0;
        else if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        int low=1;
        int high=nums.size()-2;
        int mid=(low+high)/2;
        while(low<=high)
        {
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]>nums[mid-1])
            {
                low=mid+1;
                mid=(low+high)/2;
            }
            else if(nums[mid]>nums[mid+1])
            {
                high=mid-1;
                mid=(low+high)/2;
            }
            else
                mid--;
        }
        return -1;
    }
};