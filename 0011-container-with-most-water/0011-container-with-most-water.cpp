class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=(min(height[l],height[r]))*(r-l);
        int maxarea=area;
        while(l<r){
            if(height[l]<=height[r])
                l++;
            else
                r--;
            maxarea=max(maxarea,(min(height[l],height[r]))*(r-l));
        }
        return maxarea;
    }
};