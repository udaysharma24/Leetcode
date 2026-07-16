class Solution {
public:
    bool doable(vector<int> nums, int max, int cuts){
        int acc=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>max)
                return false;
            else if(acc+nums[i]<=max)
                acc+=nums[i];
            else{
                cuts--;
                acc=nums[i];
                if(cuts<0)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int high=accumulate(nums.begin(),nums.end(),0);
        int low=*max_element(nums.begin(),nums.end());
        int cuts=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(doable(nums,mid,k-1))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};