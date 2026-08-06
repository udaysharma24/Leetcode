class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp=n;
        int mul=1;
        while(temp>0){
            mul*=(temp%10);
            temp/=10;
        }
        if(mul%t==0)
            return n;
        else{
            mul=1;
            int temp1=n;
            int temp2=n;
            while(mul%t!=0){
                mul=1;
                temp1++;
                temp2=temp1;
                while(temp2>0){
                    mul*=(temp2%10);
                    temp2/=10;
                }
            }
            return temp1;
        }
    }
};