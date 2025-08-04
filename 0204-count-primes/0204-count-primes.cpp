class Solution {
public:
    void isprime(vector<bool> &prime, int n){
        for(int i=2; i<=((n+1)/2); i++)
        {
            for(int j=(2*i); j<=n; j+=i)
            {
                prime[j]= false;
            }
        }
    }
    int countPrimes(int n) {
        vector<bool> prime(5000001, true);
        isprime(prime, n);
        int cnt=0;
        for(int i=2; i<n; i++)
        {
            if(prime[i])
                cnt++;
        }
        return cnt;
    }
};