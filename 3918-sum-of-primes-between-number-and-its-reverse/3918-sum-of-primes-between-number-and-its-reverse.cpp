class Solution {
public:
    bool isprime(int num){
        for(int i=2; i<=sqrt(num); i++){
            if(num%i==0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string s1=to_string(n);
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n1=stoi(s1);
        int n2=stoi(s2);
        int sum=0;
        for(int i=max(2,min(n1,n2)); i<=max(n1,n2); i++){
            if(isprime(i))
                sum+=i;
        }
        return sum;
    }
};