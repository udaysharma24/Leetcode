class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q=queries.size();
        vector<int> arr(q);
        vector<pair<int,int>> vp(queries.size());
        for(int i=0; i<queries.size(); i++){
            vp[i]={queries[i],i};
        }
        sort(vp.begin(),vp.end(),[](pair<int,int>& a, pair<int,int>& b){
            return a.first<b.first;
        });
        sort(logs.begin(),logs.end(),[](vector<int>& a, vector<int>& b){
            if(a[1]==b[1])
                return a[0]<b[0];
            return a[1]<b[1];
        });
        vector<int> freq(n+1,0);
        int active=0;
        int l=0;
        int r=0;
        for(int i=0; i<q; i++){
            int start=vp[i].first-x;
            int end=vp[i].first;
            int index=vp[i].second;
            int count=0;
            while(r<logs.size() && logs[r][1]<=end){
                int server=logs[r][0];

                if(freq[server]==0)
                    active++;

                freq[server]++;
                r++;
            }

            while(l<r && logs[l][1]<start){
                int server=logs[l][0];

                freq[server]--;

                if(freq[server]==0)
                    active--;

                l++;
            }

            arr[index]=n-active;
        }
        return arr;
    }
};