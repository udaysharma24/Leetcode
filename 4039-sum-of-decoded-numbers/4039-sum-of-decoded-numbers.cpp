class Solution {
public:
    long long int MOD=(long long)1e9+7;
    long long int findpower(long long int x, long long int y){
        if(y==0)
            return 1;
        int halfpower;
        if(y%2==0)
            halfpower=findpower(x,y/2);
        else
            halfpower=findpower(x,(y-1)/2);
        long long int result=((halfpower%MOD)*(halfpower%MOD))%MOD;
        if(y%2==1)
            result*=x;
        return result%MOD;
    }
    int sumDecoded(vector<long long>& nums) {
        long long int sum=0LL;
        long long int width=0LL;
        long long int d=0LL;
        for(int i=0; i<nums.size(); i++){
            width=(long long)(nums[i]%10);
            d=floor((long long)(nums[i])/10);
            string s=to_string(d);
            // cout<<s<<"\n";
            string x_str=s.substr(0,width);
            string y_str=s.substr(width,s.length()-width);
            long long int x=stoll(x_str);
            long long int y=stoll(y_str);
            // cout<<x<<" "<<y<<"\n";
            long long int ans=findpower(x,y);
            // long long int ans=((long long)pow(x,y))%MOD;
            // cout<<ans<<"\n";
            sum+=ans;
            sum%=MOD;
            // cout<<sum<<"\n";
        }
        return int(sum);
    }
};