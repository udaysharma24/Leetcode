class Solution {
public:
    int countCommas(int n) {
        string s=to_string(n);
        int digits=s.length();
        if(digits<4)
            return 0;
        int earlydig=4;
        int ans=0;
        while(earlydig<digits){
            ans+=(9*pow(10,earlydig-1));
            earlydig++;
        }
        ans+=(n-pow(10,digits-1)+1);
        return ans;
    }
};