class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int digsum=0;
        int digprod=1;
        while(temp>0){
            digsum+=(temp%10);
            digprod*=(temp%10);
            temp/=10;
        }
        if(n%(digsum+digprod)==0)
            return true;
        else
            return false;
    }
};