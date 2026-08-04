class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty())
            return ans;
        string range=to_string(nums[0]);
        int start=nums[0];
        int end=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1)
                end++;
            else{
                if(start!=end){
                    range+="->";
                    range+=(to_string(end));
                }
                ans.push_back(range);
                range="";
                start=nums[i];
                end=nums[i];
                range+=to_string(start);
            }
        }
        if(start!=end){
            range+="->";
            range+=(to_string(end));
        }
        ans.push_back(range); 
        return ans;
    }
};