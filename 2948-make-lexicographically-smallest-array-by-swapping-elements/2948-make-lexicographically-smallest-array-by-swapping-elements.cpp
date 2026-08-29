class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int index=0;
        map<int,int> m;
        map<int,deque<int>> elements;
        m[temp[0]]=index;
        elements[index].push_back(temp[0]);
        for(int i=1; i<temp.size(); i++){
            if(temp[i]-temp[i-1]<=limit){
                m[temp[i]]=index;
                elements[index].push_back(temp[i]);
            }
            else{
                index++;
                m[temp[i]]=index;
                elements[index].push_back(temp[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            int group=m[nums[i]];
            nums[i]=elements[group][0];
            elements[group].pop_front();
        }
        return nums;
    }
};