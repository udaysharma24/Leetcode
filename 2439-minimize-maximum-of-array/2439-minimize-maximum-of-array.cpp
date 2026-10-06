class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            vector<long long int> temp(nums.begin(),nums.end());
            for(int i=n-1; i>=1; i--){
                if(temp[i]>mid){
                    long long int diff=temp[i]-mid;
                    temp[i]=mid;
                    temp[i-1]+=(long long)diff;
                }
            }
            long long int mx=*max_element(temp.begin(),temp.end());
            if(mx<=mid){
                ans=min(mid,ans);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};