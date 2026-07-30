class Solution {
public:
    int MOD=1e9+7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int countValidSequences(int n, int k) {
        if(n%2==0 && k==1)
            return 1;
        else if(k==1 || k==n)
            return 0;
        else{
            long long int total_seq=1;
            long long int total_den=1;
            for(int i=1; i<=k-1; i++){
                total_seq=(total_seq*(n-i))%MOD;
                total_den=(total_den*i)%MOD;
            }
            total_seq=(total_seq*power(total_den,MOD-2))%MOD;
            int even_seq;
            if((n-k)%2==1)
                even_seq=int(total_seq%MOD);
            else{
                int m=(n-k)/2;
                long long int odd_seq=1;
                long long int odd_den=1;
                for(int i=1; i<=k-1; i++){
                    odd_seq=(odd_seq*(m+k-i))%MOD;
                    odd_den=(odd_den*i)%MOD;
                }
                odd_seq=(odd_seq*power(odd_den,MOD-2))%MOD;
                even_seq=int((total_seq-odd_seq+MOD)%MOD);
            }
            return even_seq;
        }
    }
};