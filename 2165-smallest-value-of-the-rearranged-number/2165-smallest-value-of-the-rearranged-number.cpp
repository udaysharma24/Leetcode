class Solution {
public:
    long long smallestNumber(long long num) {
        if(num<0){
            long long int temp=-num;
            vector<int> digits;
            while(temp>0){
                digits.push_back(temp%10);
                temp/=10;
            }
            int n=digits.size();
            sort(digits.begin(),digits.end(),greater<int>());
            long long int ans=0LL;
            for(int i=n-1; i>=0; i--){
                ans+=(pow(10,n-1-i)*digits[i]);
            }
            return -ans;
        }
        else if(num==0)
            return 0LL;
        else{
            long long int temp=num;
            vector<int> digits;
            while(temp>0){
                digits.push_back(temp%10);
                temp/=10;
            }
            int n=digits.size();
            sort(digits.begin(),digits.end());
            if(digits[0]==0){
                for(int i=0; i<n; i++){
                    if(digits[i]!=0){
                        swap(digits[i],digits[0]);
                        break;
                    }
                }
            }
            long long int ans=0LL;
            for(int i=n-1; i>=0; i--){
                ans+=(pow(10,n-1-i)*digits[i]);
            }
            return ans;
        }
    }
};