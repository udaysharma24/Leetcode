class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int> target(n,-1);
        for(int i=0; i<n; i++){
            if(target[index[i]]==-1)
                target[index[i]]=nums[index[i]];
            else{
                int temp1=target[index[i]];
                for(int j=index[i]; j<n-1; j++){
                    int temp2=target[j+1];
                    target[j+1]=temp1;
                    temp1=temp2;
                }
                target[index[i]]=nums[i];
            }
        }
        return target;
    }
};