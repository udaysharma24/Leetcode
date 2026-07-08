class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int qsize=queries.size();
        int n=s.length();
        const long long mod = 1000000007LL;
        vector<int> ans;
        vector<int> prefixsum(n,0);
        vector<long long int> finalvals(n);
        vector<long long int> pow10(n);
        vector<int> nonzero(n,0);
        int distinctcnt=0;
        prefixsum[0]=int(s[0])-48;
        for(int i=0; i<n; i++){
            if(i==0 && s[i]=='0')
                nonzero[i]=0;
            if(i==0 && s[i]!='0')
                nonzero[i]=1;
            if(s[i]!='0' && i>0)
                nonzero[i]=nonzero[i-1]+1;
            if(s[i]=='0' && i>0)
                nonzero[i]=nonzero[i-1];
            if(i>0)
                prefixsum[i]=(int(s[i])-48)+prefixsum[i-1];
        }
        if(s[0]=='0')
            finalvals[0]=(long long)0;
        else
            finalvals[0]=((long long)(int(s[0])-48))%mod;
        pow10[0]=1;
        for(int i=1; i<n; i++){
            if(s[i]!='0'){
                finalvals[i]=(long long)(10*(finalvals[i-1]%mod))+(long long)(int(s[i])-48);
                finalvals[i]%=mod;
                pow10[i]=(pow10[i-1]*10)%mod;
            }
            else{
                finalvals[i]=finalvals[i-1];
                pow10[i]=(pow10[i-1]*10)%mod;
            }
        }
        for(int i=0; i<qsize; i++){
            int l=queries[i][0];
            int r=queries[i][1];
            long long int sum;
            long long int x=0;
            if(l>0){
                int k=nonzero[r]-nonzero[l-1];
                sum=((long long)(prefixsum[r]-prefixsum[l-1]))%mod;
                long long int multiplier=pow10[k];
                x=(finalvals[r]-((multiplier*finalvals[l-1])%mod)%mod+mod)%mod;
            }
            else{
                sum=(long long)(prefixsum[r]);
                x=finalvals[r]%mod;
            }
            long long int final=((x%mod)*sum)%(mod);
            cout<<final<<"\n";
            ans.push_back(final);
        }
        return ans;
    }
};