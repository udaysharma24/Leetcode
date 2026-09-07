class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int tempr=red;
        int tempb=blue;
        int cnt1=1;
        int height1=0;
        while(tempr>=cnt1 && tempb>=cnt1){
            if(cnt1%2==1){
                tempr-=cnt1;
                cnt1++;
            }
            else{
                tempb-=cnt1;
                cnt1++;
            }
        }
        if(tempr>=cnt1 && cnt1%2==1){
            tempr-=cnt1;
            cnt1++;
        }
        else if(tempb>=cnt1){
            tempb-=cnt1;
            cnt1++;
        }
        height1=max(height1,cnt1-1);
        tempr=red;
        tempb=blue;
        cnt1=1;
        while(tempr>=cnt1 && tempb>=cnt1){
            if(cnt1%2==1){
                tempb-=cnt1;
                cnt1++;
            }
            else{
                tempr-=cnt1;
                cnt1++;
            }
        }
        if(tempb>=cnt1 && cnt1%2==1){
            tempb-=cnt1;
            cnt1++;
        }
        else if(tempr>=cnt1){
            tempr-=cnt1;
            cnt1++;
        }
        height1=max(height1,cnt1-1);
        return height1;
    }
};