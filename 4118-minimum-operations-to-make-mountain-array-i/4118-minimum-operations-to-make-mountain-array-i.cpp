class Solution {
public:
    #define ll long long 
    int minOperations(vector<int>& a) {
        int n=a.size();
        if(n<=2)
            return -1;
        vector<vector<ll>> dpl(n + 1, vector<ll>(2000+1,1e8));
        vector<vector<ll>> prefix(n + 1, vector<ll>(2000+1,1e8));
        for(ll j=1;j<=2000;j++){
            dpl[0][j] = abs(a[0]-j);
            prefix[0][j] = min(prefix[0][j-1],dpl[0][j]);
        }


        dpl[0][0] = 1e8; 
        for(ll i=1;i<=n-1;i++){
            for(ll j=1;j<=2000;j++){
                dpl[i][j] = min(dpl[i][j],abs(a[i]-j) + prefix[i-1][j-1]);
                prefix[i][j] = min(prefix[i][j-1],dpl[i][j]);
            }
        }

        vector<vector<ll>> dpr(n + 1, vector<ll>(2000+1,1e8));
        vector<vector<ll>> suffix(n + 1, vector<ll>(2000+1,1e8));
        for(ll j=1;j<=2000;j++){
            dpr[n-1][j] = abs(a[n-1]-j);
            suffix[n-1][j] = min(suffix[n-1][j-1],dpr[n-1][j]);
        }
        
        dpr[n-1][0] = 1e8; 
        for(ll i=n-1;i>=0;i--){
            for(ll j=1;j<=2000;j++){
                dpr[i][j] = min(dpr[i][j],abs(a[i]-j) + suffix[i+1][j-1]);
                suffix[i][j] = min(suffix[i][j-1],dpr[i][j]);
            }
        }

        ll answer = 1e8;

        for(ll i=1;i<=n-2;i++){

            for(ll j=1;j<=2000;j++){
                ll first = abs(a[i]-j); 
                ll second = prefix[i-1][j-1]; 
                ll third = suffix[i+1][j-1]; 
                answer = min(answer,first+second+third); 
            }

        }

        if(answer>=1e8){
            return -1;
        } 

        return answer;
    }
};