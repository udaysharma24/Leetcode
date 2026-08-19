class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n,false);
        sort(nums.begin(),nums.end());
        int index=0;
        for(int i=0; i<n; i++){
            if(2*nums[i]>nums[n-1]){
                index=i;
                break;
            }
        }
        // for(int i=0; i<n; i++){
        //     cout<<nums[i]<<" ";
        // }
        int l=0;
        int r=index;
        int marked=0;
        int maxmarked=0;
        while(l<index && r<n){
            if(nums[r]>=2*nums[l]){
                l++;
                r++;
                marked+=2;
            }
            else
                r++;
        }
        maxmarked=max(marked,maxmarked);
        l=0;
        r=(n+1)/2;
        marked=0;
        maxmarked=0;
        while(l<index && r<n){
            if(nums[r]>=2*nums[l]){
                l++;
                r++;
                marked+=2;
            }
            else
                r++;
        }
        maxmarked=max(marked,maxmarked);
        return maxmarked;
    }
};