#define ll long long
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<ll,ll>> v;
        for(int i=0; i<n; i++){
            string revtemp=to_string(nums[i]);
            sort(revtemp.begin(),revtemp.end(),greater<char>());
            ll arranged=stoll(revtemp);
            ll diff=arranged-(ll)nums[i];
            v.push_back({diff,arranged});
        }
        sort(v.begin(),v.end(),[](pair<ll,ll>& a, pair<ll,ll>& b){
            return a.first>b.first;
        });
        int cnt=0;
        int i=0;
        ll ans=0LL;
        while(i<n){
            vector<int> digits;
            int temp=v[i].second;
            string s=to_string(temp);
            while(temp>0){
                digits.push_back(temp%10);
                temp/=10;
            }
            if(v[i].first>0 && cnt<k){
                sort(s.begin(),s.end(),greater<char>());
                ll num=stoll(s);
                ans+=num;
                cnt++;
            }
            else
                ans+=(long long)(v[i].second-v[i].first);
            i++;
        }
        return ans;
    }
};