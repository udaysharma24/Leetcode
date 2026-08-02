class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,int> um;
        stack<int> ms;
        for(int i=n-1; i>=0; i--){
            if(ms.empty()){
                ms.push(i);
                um[nums2[i]]=-1;
            }
            else if(nums2[i]>nums2[ms.top()]){
                while(!ms.empty() && nums2[i]>nums2[ms.top()]){
                    ms.pop();
                }
                if(ms.empty()){
                    ms.push(i);
                    um[nums2[i]]=-1;
                }
                else{
                    um[nums2[i]]=nums2[ms.top()];
                    ms.push(i);
                }
            }
            else if(nums2[i]<nums2[ms.top()]){
                um[nums2[i]]=nums2[ms.top()];
                ms.push(i);
            }
        }
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            ans[i]=um[nums1[i]];
        }
        return ans;
    }
};