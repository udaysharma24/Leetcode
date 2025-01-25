class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int mid=(low+high)/2;
        int sum=0;
        int ans=0;
        while(low<=high)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]%mid==0)
                    sum+=(nums[i]/mid);
                else
                    sum+=((nums[i]/mid)+1);
            }
            if(sum<threshold)
            {
                ans=mid;
                high=mid-1;
                mid=(low+high)/2;
                sum=0;
            }
            else if(sum==threshold)
            {
                ans=mid;
                high=mid-1;
                mid=(low+high)/2;
                sum=0;
            }
            else if(sum>threshold)
            {
                low=mid+1;
                mid=(low+high)/2;
                sum=0;
            }
        }
        return ans;
    }
};