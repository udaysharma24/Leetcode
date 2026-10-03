class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        string ans="";
        vector<string> vs;
        for(int i=0; i<n; i++){
            string s=to_string(nums[i]);
            vs.push_back(s);
        }
        sort(vs.begin(),vs.end(),[](string &a, string &b){
            return a+b>b+a;
        });
        for(int i=0; i<vs.size(); i++){
            ans+=vs[i];
        }
        bool allzero=false;
        for(int i=0; i<vs.size()-1; i++){
            if(vs[i]==vs[i+1] && vs[i]=="0")
                allzero=true;
            else{
                allzero=false;
                break;
            }
        }
        if(allzero)
            return "0";
        return ans;
    }
};