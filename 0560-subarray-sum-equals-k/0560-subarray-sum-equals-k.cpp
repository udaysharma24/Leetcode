class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // if(n==1){
        //     if(nums[0]!=k)
        //         return 0;
        //     else
        //         return 1;
        // }
        // vector<int> psum(n);
        // psum[0]=nums[0];
        // int cnt=0;
        // for(int i=1; i<nums.size(); i++){
        //     psum[i]=psum[i-1]+nums[i];
        //     if(psum[i]==k)
        //         cnt++;
        // }
        // int l=0;
        // int r=0;
        // while(l<=r && r<n){
        //     if(psum[r]-psum[l]<k)
        //         r++;
        //     else if(psum[r]-psum[l]==k){
        //         cnt++;
        //         r++;
        //     }
        //     else
        //         l++;
        // }
        // return cnt;

        unordered_map<int,int> um;
        um[0]=1;
        int psum=0;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            psum+=nums[i];
            if(um.find(psum-k)!=um.end())
                cnt+=um[psum-k];
            um[psum]++;
        }
        return cnt;
    }
};