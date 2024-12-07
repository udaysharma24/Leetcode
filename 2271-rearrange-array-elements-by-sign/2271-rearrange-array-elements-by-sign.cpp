class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0;
        int n=1;
        vector<int> arr(nums.size());
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
            {
                arr[p]=nums[i];
                p+=2;
            }
            else if(nums[i]<0)
            {
                arr[n]=nums[i];
                n+=2;
            }
        }
        return arr;
    }
};