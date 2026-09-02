class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int la=abs(ax2-ax1);
        int wa=abs(ay2-ay1);
        int lb=abs(bx2-bx1);
        int wb=abs(by2-by1);
        int total_area=(la*wa)+(lb*wb);
        int intersected_area=0;
    
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);

        int bottom = max(ay1, by1);
        int top = min(ay2, by2);

        if (left < right && bottom < top) {
            intersected_area = (right - left) * (top - bottom);
        }
        cout<<intersected_area;
        return total_area-intersected_area;
    }
};