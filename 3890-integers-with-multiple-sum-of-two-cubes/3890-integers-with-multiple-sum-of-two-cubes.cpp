class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int cbrt_n= ceil(cbrt(n));
        cout<<cbrt_n<<"\n";
        vector<int> ans;
        vector<int> ans2;
        unordered_map<int,int> um;
        unordered_map<int,bool> um2;
        if(n==1)
            return ans2;
        for(int i=1; i<=cbrt_n; i++)
        {
            for(int j=i; j<=cbrt_n; j++)
            {
                int result= pow(i,3)+ pow(j,3);
                if(result<=n)
                {
                    ans.push_back(result);
                    um[result]++;
                }
            }
        }
        // for(int i=0; i<ans.size(); i++)
        // {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<"\n";
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size()-1; i++)
        {
            if(um[ans[i]]>=2 && um2[ans[i]]==false)
            {
                ans2.push_back(ans[i]);
                um2[ans[i]]=true;
            }
        }
        return ans2;
    }
};