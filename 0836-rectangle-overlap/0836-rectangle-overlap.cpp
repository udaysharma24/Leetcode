class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x11=rec1[0];
        int x12=rec1[2];
        int y11=rec1[1];
        int y12=rec1[3];
        int x21=rec2[0];
        int x22=rec2[2];
        int y21=rec2[1];
        int y22=rec2[3];
        long long int right=min(x12,x22);
        long long int left=max(x11,x21);
        long long int bottom=max(y11,y21);
        long long int up=min(y12,y22);
        long long int area=(long long)((right-left)*(up-bottom));
        if(right-left>0 && area>0)
            return true;
        else
            return false;
    }
};