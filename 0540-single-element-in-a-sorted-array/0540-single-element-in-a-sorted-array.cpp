class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[nums.size()-1]!=nums[nums.size()-2])
            return nums[nums.size()-1];
        else
        {
            int low=1;
            int high=nums.size()-2;
            int mid=(low+high)/2;
            while(low<=high)
            {
                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                    return nums[mid];
                else if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1]))
                {
                    low=mid+1;
                    mid=(low+high)/2;
                }
                else if((mid%2==0 && nums[mid]==nums[mid-1]) || (mid%2==1 && nums[mid]==nums[mid+1]))
                {
                    high=mid-1;
                    mid=(low+high)/2;
                }
            }
            return -1;
        }
    }
};