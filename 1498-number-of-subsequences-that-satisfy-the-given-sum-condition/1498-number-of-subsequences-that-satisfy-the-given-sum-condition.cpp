class Solution {
public:
    int MOD=1e9+7;
    int power(int x, int y){
        if(y==0)
            return 1;
        int halfpower=power(x,y/2);
        int result=(1LL*(halfpower%MOD)*(halfpower%MOD))%MOD;
        if(y%2==1)
            result=(x*result)%MOD;
        return result;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mn=nums[0];
        int mx=0;
        vector<int> actual;
        for(int i=0; i<n; i++){
            if(nums[i]+mn<=target){
                mx=max(mx,nums[i]);
                actual.push_back(nums[i]);
            }
        }
        int netans=0;
        int m=actual.size();
        int l=0;
        int r=m-1;
        cout<<l<<" "<<r<<"\n";
        while(l<=r && l<m && r>=0){
            netans+=(power(2,r-l));
            cout<<netans<<"\n";
            netans%=MOD;
            l++;
            while(l<=r && actual[l]+actual[r]>target){
                r--;
            }
            cout<<l<<" "<<r<<"\n";
        }
        return netans;
    }
};