class Solution {
public:
    int bsearch(vector<int> nums, int low, int high, int target)
    {
        if(low>high)
            return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            return bsearch(nums,mid+1,high,target);
        else
            return bsearch(nums,low,mid-1,target);
    }
    int search(vector<int>& nums,int target) {
        return bsearch(nums,0,nums.size()-1,target);
    }
};