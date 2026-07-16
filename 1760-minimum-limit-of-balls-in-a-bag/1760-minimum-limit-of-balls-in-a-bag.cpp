class Solution {
public:
    long long int minoperations(vector<int> nums, int mid){
        long long int acc=0;
        int n=nums.size();
        for(int i=n-1; i>=0; i--){
            if(nums[i]>mid){
                acc+=((nums[i]-1)/mid);
            }
        }
        return acc;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=1e9;
        sort(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(minoperations(nums,mid)>(long long)maxOperations)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};