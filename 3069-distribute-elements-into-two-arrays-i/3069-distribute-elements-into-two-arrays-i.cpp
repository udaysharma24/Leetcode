class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int r1=0,r2=0;
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
            if(arr1[r1]>arr2[r2]){
                arr1.push_back(nums[i]);
                r1++;
            }
            else{
                arr2.push_back(nums[i]);
                r2++;
            }
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};