class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> heights(n+1,0);
        int max_height=0;
        heights[0]=0;
        for(int i=1; i<n+1; i++){
            heights[i]=heights[i-1]+gain[i-1];
            max_height=max(heights[i],max_height);
        }
        return max_height;
    }
};