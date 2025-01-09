class Solution {
public:
    void merge(vector<int> &nums, long long int low, long long int mid, long long int high)
    {
        long long int ans=0;
        vector<long long int> temp;
        long long int left=low;
        long long int right=mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for(long long int i=low; i<=high; i++)
        {
            nums[i]=temp[i-low];
        }
    }
    long long int mergesort(vector<int> &nums, long long int low, long long int high)
    {
        long long int ans=0;
        long long int mid=(low+high)/2;
        if(low>=high)
            return ans;
        ans+=mergesort(nums,low,mid);
        ans+=mergesort(nums,mid+1,high);
        long long int right=mid+1;
        for(long long int i=low; i<=mid; i++)
        {
            while(right<=high && nums[i]>2*(long long int)nums[right])
            {
                right++;
            }
            ans+=(right-(mid+1));
        }
        merge(nums,low,mid,high);
        return ans;
    }
    long long int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};