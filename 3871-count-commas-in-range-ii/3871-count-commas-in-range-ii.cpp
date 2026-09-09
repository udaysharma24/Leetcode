class Solution {
public:
    long long countCommas(long long n) {
        string s=to_string(n);
        int len=s.length();
        long long int ans=0LL;
        if(len<4)
            return 0LL;
        else{
            if(len>=16){
                ans+=(5*(n-pow(10,len-1)+1));
                len--;
            }
            else if(len>=13){
                ans+=(4*(n-pow(10,len-1)+1));
                len--;
            }
            else if(len>=10){
                ans+=(3*(n-pow(10,len-1)+1));
                len--;
            }
            else if(len>=7){
                ans+=(2*(n-pow(10,len-1)+1));
                len--;
            }
            else if(len>=4){
                ans+=(n-pow(10,len-1)+1);
                len--;
            }
            while(len>=4){
                if(len>=13){
                    ans+=(9*4*pow(10,len-1));
                    len--;
                }
                else if(len>=10){
                    ans+=(9*3*pow(10,len-1));
                    len--;
                }
                else if(len>=7){
                    ans+=(9*2*pow(10,len-1));
                    len--;
                }
                else if(len>=4){
                    ans+=(9*pow(10,len-1));
                    len--;
                }
            }
        }
        return ans;
    }
};