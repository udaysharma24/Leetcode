class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int sum=0;
        for(int i=0; i<s.length(); i++){
            string k{s[i]};
            int dig=stoi(k);
            if(i%2==0)
                sum+=dig;
            else
                sum-=dig;
        }
        return sum;
    }
};