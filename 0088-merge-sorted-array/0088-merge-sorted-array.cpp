class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        nums1.reserve(m+n);
        int l=0, r=0;
        int index=0;
        while(l<m && r<n){
            if(nums1[l]<nums2[r]){
                ans[index]=nums1[l];
                l++;
            }
            else{
                ans[index]=nums2[r];
                r++;
            }
            index++;
        }
        while(l<m){
            ans[index]=nums1[l];
            index++;
            l++;
        }
        while(r<n){
            ans[index]=nums2[r];
            index++;
            r++;
        }
        nums1=ans;
    }
};