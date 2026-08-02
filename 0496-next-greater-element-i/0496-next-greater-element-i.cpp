class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> nge(n);
        stack<int> ms;
        for(int i=n-1; i>=0; i--){
            if(ms.empty()){
                ms.push(i);
                nge[i]=-1;
            }
            else if(nums2[i]>nums2[ms.top()]){
                while(!ms.empty() && nums2[i]>nums2[ms.top()]){
                    ms.pop();
                }
                if(ms.empty()){
                    ms.push(i);
                    nge[i]=-1;
                }
                else{
                    nge[i]=nums2[ms.top()];
                    ms.push(i);
                }
            }
            else if(nums2[i]<nums2[ms.top()]){
                nge[i]=nums2[ms.top()];
                ms.push(i);
            }
        }
        for(int j=0; j<n; j++){
            cout<<nge[j]<<" ";
        }
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=nge[j];
                    break;
                }
            }
        }
        return ans;
    }
};