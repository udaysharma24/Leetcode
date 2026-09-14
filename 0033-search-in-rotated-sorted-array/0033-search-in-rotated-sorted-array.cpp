class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int index=n;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                index=i;
                break;
            }
        }
        int low1=0;
        int high1=index-1;
        int low2=index;
        int high2=n-1;
        while(low1<=high1){
            int mid1=(low1+high1)/2;
            if(target<nums[mid1])
                high1=mid1-1;
            else if(target==nums[mid1])
                return mid1;
            else
                low1=mid1+1;
        }
        while(low2<=high2){
            int mid2=(low2+high2)/2;
            if(target<nums[mid2])
                high2=mid2-1;
            else if(target==nums[mid2])
                return mid2;
            else
                low2=mid2+1;
        }
        return -1;
    }
};