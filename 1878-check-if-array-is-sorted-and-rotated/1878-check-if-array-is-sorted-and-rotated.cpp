class Solution {
public:
    bool check(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))
            return true;
        else
        {
            int i1=1;
            bool flag1=true, flag2=true;
            for(int i=0; i<nums.size()-1; i++)
            {
                if(nums[i]<=nums[i+1])
                    i1++;
                else if(flag1==false)
                    break;
                else
                    flag1=false;
            }
            for(int i=i1; i<nums.size()-1; i++)
            {
                if(nums[i]<=nums[i+1])
                    i1++;
                else
                {
                    flag2=false;
                    return false;
                }
            }
            if(flag1==false && flag2==false)
                return false;
            else if(nums[0]>=nums[i1])
                return true;
            else
                return false;
        }
    }
};