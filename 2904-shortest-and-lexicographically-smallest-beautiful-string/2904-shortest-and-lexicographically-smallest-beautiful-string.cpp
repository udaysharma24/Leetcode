class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        vector<int> prefixones(n);
        unordered_map<int,int> um;
        if(s[0]=='1')
            prefixones[0]=1;
        else
            prefixones[0]=0;
        um[prefixones[0]]++;
        for(int i=1; i<n; i++){
            if(s[i]=='1')
                prefixones[i]=prefixones[i-1]+1;
            else
                prefixones[i]=prefixones[i-1];
            um[prefixones[i]]++;
        }
        if(um[k]==0)
            return "";
        if(k==1){
            if(um[k]>=1)
                return "1";
            else
                return "";
        }
        int l=0;
        int r=0;
        int minlength=INT_MAX;
        string minstring="";
        vector<string> ans;
        while(l<=r && r<prefixones.size()){
            if(prefixones[r]-prefixones[l]+1<k)
                r++;
            if(r<n && l<=r && prefixones[r]-prefixones[l]+1==k && r-l+1==minlength && s[r]=='1' && s[l]=='1'){
                minlength=r-l+1;
                minstring=s.substr(l,r-l+1);
                ans.push_back(minstring);
                r++;
                cout<<minstring<<"\n";
            }
            if(r<n && l<=r && prefixones[r]-prefixones[l]+1==k && r-l+1<minlength && s[r]=='1' && s[l]=='1'){
                minlength=r-l+1;
                minstring=s.substr(l,r-l+1);
                r++;
                ans.push_back(minstring);
                cout<<minstring<<"\n";
            }
            else{
                while(r<n && l<=r && prefixones[r]-prefixones[l]+1>=k){
                    if(r<n && l<=r && prefixones[r]-prefixones[l]+1==k && r-l+1<minlength && s[r]=='1' && s[l]=='1'){
                        minlength=r-l+1;
                        minstring=s.substr(l,r-l+1);
                        ans.push_back(minstring);
                        cout<<minstring<<"\n";
                        // cout<<ans[0]<<" "<<ans[1]<<"\n";
                    }
                    if(r<n && l<=r && prefixones[r]-prefixones[l]+1==k && r-l+1==minlength && s[r]=='1' && s[l]=='1'){
                        minlength=r-l+1;
                        minstring=s.substr(l,r-l+1);
                        ans.push_back(minstring);
                        // cout<<ans[0]<<" "<<ans[1]<<"\n";
                        cout<<minstring<<"\n";
                    }
                    l++;
                }
            }
        }
        // cout<<ans[0]<<" "<<ans[1]<<"\n";
        sort(ans.begin(),ans.end(), [](string &a, string &b){
            if(a.length()!=b.length())
                return a.length()<b.length();
            return a<b;
        });
        // cout<<ans[0]<<" "<<ans[1]<<"\n";
        return ans[0];
    }
};