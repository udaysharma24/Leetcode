class Solution {
public:
    int maxProduct(int n) {
        int firstmax=0,secondmax=0;
        while(n!=0){
            if((n%10)>firstmax){
                secondmax=firstmax;
                firstmax=n%10;
            }
            else if((n%10)>secondmax)
                secondmax=n%10;
            n/=10;
        }
        return firstmax*secondmax;
    }
};