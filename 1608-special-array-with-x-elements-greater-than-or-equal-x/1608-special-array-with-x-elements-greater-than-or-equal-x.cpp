class Solution {
public:
    int specialArray(vector<int>& nums) {
        int low=1;
        int high=nums.size();
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]>=mid)
                    cnt++;
            }
            if(cnt==mid){
                ans=mid;
                low=mid+1;
            }
            else if(cnt<mid)
                high=mid-1;
            else if(cnt>mid)    
                low=mid+1;
        }
        return ans;
    }
};