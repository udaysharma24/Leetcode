class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(int i=0; i<nums.size()-2; i++)
        {
            if(nums[i]==0)
            {
                nums[i]=1;
                if(nums[i+1]==1)
                    nums[i+1]=0;
                else if(nums[i+1]==0)
                    nums[i+1]=1;
                if(nums[i+2]==1)
                    nums[i+2]=0;
                else if(nums[i+2]==0)
                    nums[i+2]=1;
                c++;
            }
        }
        if(nums[nums.size()-1]==1 && nums[nums.size()-2]==1)
            return c;
        else
            return -1;
    }
};