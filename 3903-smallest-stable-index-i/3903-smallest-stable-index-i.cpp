class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int iscore=0;
        int minindex=1e9;
        for(int i=0; i<n; i++){
            iscore=*max_element(nums.begin(),nums.begin()+i+1)-*min_element(nums.begin()+i,nums.begin()+n);
            if(iscore<=k)
                minindex=min(i,minindex);
        }
        if(minindex==1e9)
            minindex=-1;
        return minindex;
    }
};