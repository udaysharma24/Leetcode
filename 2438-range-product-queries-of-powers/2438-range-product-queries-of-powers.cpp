class Solution {
public:
    int MOD=1e9+7;
    long long int mul(int a, int b){
        return (long long)(((long long)(a%MOD)*(long long)(b%MOD))%MOD);
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<int> ans(q);
        vector<int> power;
        int temp=n;
        if(temp%2==1){
            power.push_back(1);
            temp--;
        }
        while(temp>0){
            int num=log2(temp);
            int res=pow(2,num);
            power.push_back(res);
            temp-=res;
        }
        sort(power.begin(),power.end());
        for(int i=0; i<power.size(); i++){
            cout<<power[i]<<" ";
        }
        for(int i=0; i<queries.size(); i++){
            int left=queries[i][0];
            int right=queries[i][1];
            int result=1;
            for(int i=left; i<=right; i++){
                result=mul(result,power[i]);
            }
            ans[i]=result;
        }
        return ans;
    }
};