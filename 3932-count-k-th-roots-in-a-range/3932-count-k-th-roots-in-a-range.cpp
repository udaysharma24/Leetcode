class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int cnt=0;
        int x=0;
        if(k==1)
            return (r-l+1);
        while(pow(x,k)<l)  
        {
            x++;
        }  
        while(pow(x,k)>=l && pow(x,k)<=r)
        {
            cnt++;
            x++;
        }
        return cnt;
    }
};