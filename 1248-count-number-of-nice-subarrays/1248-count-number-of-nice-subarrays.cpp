class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> oddindex;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2==1)
                oddindex.push_back(i);
        }
        int m=oddindex.size();
        if(m<k)
            return 0;
        int ans=0;
        for(int i=0; i<m; i++){
            int left=i;
            int right=i+k-1;
            if(left==0 && right==m-1){
                int temp1=oddindex[left]+1;
                int temp2=n-1-oddindex[right]+1;
                ans+=(temp1*temp2);
                break;
            }
            else if(left==0){
                int temp1=oddindex[left]+1;
                int temp2=oddindex[right+1]-oddindex[right];
                ans+=(temp1*temp2);
            }
            else if(right==m-1){
                int temp1=oddindex[left]-oddindex[left-1];
                int temp2=n-1-oddindex[right]+1;
                ans+=(temp1*temp2);
                break;
            }
            else{
                int temp1=oddindex[left]-oddindex[left-1];
                int temp2=oddindex[right+1]-oddindex[right];
                ans+=(temp1*temp2);
            }
        }
        return ans;
    }
};