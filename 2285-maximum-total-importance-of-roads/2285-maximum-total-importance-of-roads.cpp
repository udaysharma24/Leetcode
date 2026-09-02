class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        vector<pair<int,int>> vp;
        for(int i=0; i<roads.size(); i++){
            int city1=roads[i][0];
            int city2=roads[i][1];
            indegree[city1]++;
            indegree[city2]++;
        }
        for(int i=0; i<n; i++){
            vp.push_back({i,indegree[i]});
        }
        sort(vp.begin(),vp.end(),[](pair<int,int>& a, pair<int,int>& b){
            if(a.second==b.second)
                return a.first<b.first;
            return a.second>b.second;
        });
        int temp=n;
        unordered_map<int,int> priority;
        for(int i=0; i<n; i++){
            int index=vp[i].first;
            priority[index]=temp;
            temp--;
        }
        long long int maximp=0;
        for(int i=0; i<roads.size(); i++){
            int imp1=priority[roads[i][0]];
            int imp2=priority[roads[i][1]];
            maximp+=(imp1+imp2);
        }
        return maximp;
    }
};