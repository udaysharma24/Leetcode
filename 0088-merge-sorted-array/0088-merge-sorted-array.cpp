class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sub;
        for(int i=0; i<m; i++)
        {
            sub.push_back(nums1[i]);
        }
        nums1.clear();
        int start1=0;
        int start2=0;
        while(start1<m && start2<n)
        {
            if(sub[start1]<=nums2[start2])
            {
                nums1.push_back(sub[start1]);
                start1++;
            }
            else if(nums2[start2]<sub[start1])
            {
                nums1.push_back(nums2[start2]);
                start2++;
            }
        }
        while(start1<m)
        {
            nums1.push_back(sub[start1]);
            start1++;
        }
        while(start2<n)
        {
            nums1.push_back(nums2[start2]);
            start2++;
        }
    }
};