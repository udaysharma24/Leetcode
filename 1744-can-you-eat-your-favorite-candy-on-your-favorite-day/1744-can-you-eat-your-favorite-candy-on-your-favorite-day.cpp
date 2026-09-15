class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int q=queries.size();
        int n=candiesCount.size();
        vector<bool> ans(q);
        vector<long long int> psum(n);
        psum[0]=candiesCount[0];
        for(int i=1; i<n; i++){
            psum[i]=psum[i-1]+(long long)candiesCount[i];
        }
        for(int i=0; i<q; i++){
            int favtype=queries[i][0];
            int favday=queries[i][1];
            int dailycap=queries[i][2];
            long long int maxbound=psum[favtype]-1;
            long long int minbound;
            if(favtype>0)
                minbound=((psum[favtype]-candiesCount[favtype])/dailycap);
            if(favtype==0)
                minbound=0;
            if(favday>=minbound && favday<=maxbound)
                ans[i]=true;
            cout<<minbound<<" "<<maxbound<<"\n";
        }
        return ans;
    }
};