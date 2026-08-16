class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> um1;
        unordered_map<int,int> um2;
        for(int i=0; i<nums1.size(); i++){
            um1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            um2[nums2[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            while(um1[nums2[i]]>0 && um2[nums2[i]]>0){
                ans.push_back(nums2[i]);
                um1[nums2[i]]--;
                um2[nums2[i]]--;
            }
        }
        return ans;
    }
};