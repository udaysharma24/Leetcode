class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        stack<int> ms;
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(!ms.empty() && nums[i]<=nums[ms.top()])
                ms.push(i);
            else{
                while(!ms.empty() && nums[i]>nums[ms.top()]){
                    nge[ms.top()]=nums[i];
                    ms.pop();
                }
                if(nums[i]==mx){
                    nge[i]=-1;
                    continue;
                }
                ms.push(i);
            }
        }
        for(int i=0; i<n; i++){
            while(!ms.empty() && nums[i]>nums[ms.top()]){
                nge[ms.top()]=nums[i];
                ms.pop();
            }
        }
        return nge;
    }
};