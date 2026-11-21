class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1==node2)
            return node1;
        if(edges[node1]==node2 && edges[node2]==node1)
            return min(node1,node2);
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;
        vector<int> dis1(edges.size());
        vector<int> dis2(edges.size());
        vector<bool> visited1(edges.size(),false);
        vector<bool> visited2(edges.size(),false);
        queue<int> q1;
        queue<int> q2;
        q1.push(node1);
        visited1[node1]=true;
        q2.push(node2);
        visited2[node2]=true;
        int dist1=0;
        while(!q1.empty()){
            int temp=q1.front();
            q1.pop();
            v1.push_back({temp,dist1});
            dis1[temp]=dist1;
            dist1++;
            if(edges[temp]!=-1 && !visited1[edges[temp]]){
                q1.push(edges[temp]);
                visited1[edges[temp]]=true;
            }
        }
        int dist2=0;
        while(!q2.empty()){
            int temp=q2.front();
            q2.pop();
            v2.push_back({temp,dist2});
            dis2[temp]=dist2;
            dist2++;
            if(edges[temp]!=-1 && !visited2[edges[temp]]){
                q2.push(edges[temp]);
                visited2[edges[temp]]=true;
            }
        }
        vector<pair<int,int>> ans;
        unordered_map<int,int> um;
        for(int i=0; i<v1.size(); i++){
            um[v1[i].first]++;
        }
        for(int i=0; i<v2.size(); i++){
            if(um[v2[i].first]>0)
                ans.push_back(v2[i]);
        }
        sort(ans.begin(),ans.end(),[&dis1, &dis2](pair<int,int> p1, pair<int,int> p2){
            if(max(dis1[p1.first],dis2[p1.first])==max(dis1[p2.first],dis2[p2.first]))
                return p1.first<p2.first;
            return max(dis1[p1.first],dis2[p1.first])<max(dis1[p2.first],dis2[p2.first]);
        });
        if(ans.empty())
            return -1;
        else
            return ans[0].first;
    }
};