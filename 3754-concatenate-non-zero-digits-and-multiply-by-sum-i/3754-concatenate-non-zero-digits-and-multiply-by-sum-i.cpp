class Solution {
public:
    long long sumAndMultiply(int n) {
        int temp=n;
        vector<int> digits;
        while(temp>0){
            if(temp%10!=0)
                digits.push_back(temp%10);
            temp/=10;
        }
        long long int sum=(long long)(accumulate(digits.begin(),digits.end(),0));
        long long int x=0;
        int s=digits.size();
        for(int i=0; i<s; i++){
            x+=(long long)(digits[i]*pow(10,i));
        }
        return x*sum;
    }
};