class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int MOD=1e9+7;
        vector<int> prefixsum(n);
        prefixsum[0]=arr[0];
        long long int cnt=0;
        int even_prefixes=0;
        int odd_prefixes=0;
        if(prefixsum[0]%2==1){
            odd_prefixes++;
            cnt++;
        }
        else
            even_prefixes++;
        for(int i=1; i<n; i++){
            prefixsum[i]=prefixsum[i-1]+arr[i];
            if(prefixsum[i]%2==1){
                cnt++;
                cnt+=even_prefixes;
                odd_prefixes++;
            }
            else{
                cnt+=odd_prefixes;
                even_prefixes++;
            }
        }
        return int(cnt%MOD);
    }
};