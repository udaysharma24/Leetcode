class Solution {
public:
    int divcount(vector<int> nums, int arraysize)
    {
        int cnt=1;
        int size=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(size+nums[i]<=arraysize)
                size+=nums[i];
            else
            {
                cnt++;
                size=nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin()+k-1,nums.end(),0);
        int mid=(low+high)/2;
        if(nums.size()==k)
            return *max_element(nums.begin(),nums.end());
        else if(k==1)
            return accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        cout<<low<<" "<<high;
        if(low<=high)
        {
            while(low<=high)
            {
                int divcnt=divcount(nums,mid);
                if(divcnt<k)
                {
                    ans=mid;
                    high=mid-1;
                    mid=(low+high)/2;
                    cout<<"Hi1\n";
                }
                else if(divcnt==k)
                {
                    ans=mid;
                    high=mid-1;
                    mid=(low+high)/2;
                    cout<<"Hi2\n";
                }
                else if(divcnt>k)
                {
                    low=mid+1;
                    mid=(low+high)/2;
                    cout<<"Hi3\n";
                }
            }
            return ans;
        }
        else
            return low;
    }
};