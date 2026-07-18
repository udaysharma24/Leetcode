class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> absdiff(n);
        map<int,int> m1;
        map<int,int> m2;
        int sum=accumulate(nums.begin(),nums.end(),0);
        m1[0]=sum;
        m2[0]=0;
        for(int i=1; i<n; i++){
            m1[i]=m1[i-1]-nums[i-1];
            m2[i]=m2[i-1]+nums[i-1];
        }
        for(int i=0; i<n; i++){
            absdiff[i]=m1[i]-(n-i)*nums[i]+(i*nums[i])-m2[i];
        }
        return absdiff;
    }
};