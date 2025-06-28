class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)
            return false;
        while(n!=0)
        {
            if(n==1)
                return true;
            else if(n%2==1)
                return false;
            n=n>>1;
        }
        return false;
    }
};