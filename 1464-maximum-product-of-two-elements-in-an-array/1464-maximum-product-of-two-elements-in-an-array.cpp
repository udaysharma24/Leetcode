class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        int max1=pq.top();
        pq.pop();
        int max2=pq.top();
        pq.pop();
        return (max1-1)*(max2-1);
    }
};