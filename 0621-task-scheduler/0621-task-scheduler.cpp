class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> um;
        vector<char> v;
        int distinct=0;
        for(int i=0; i<tasks.size(); i++){
            if(um[tasks[i]]==0)
                distinct++;
            um[tasks[i]]++;
        }
        vector<bool> init_visited(distinct,false);
        for(int i=0; i<tasks.size(); i++){
            if(!init_visited[tasks[i]-'A']){
                pq.push({um[tasks[i]],tasks[i]});
                init_visited[tasks[i]-'A']=true;
            }
        }
        vector<bool> visited(distinct,true);
        vector<bool> completed(distinct,false);
        int count=0;
        while(count<distinct){
            int temp=0;
            while(!pq.empty() && temp<n+1){
                pair<int,char> p=pq.top();
                pq.pop();
                v.push_back(p.second);
                um[p.second]--;
                visited[p.second-'A']=false;
                if(um[p.second]==0){
                    completed[p.second-'A']=true;
                    count++;
                }
                temp++;
            }
            if(count==distinct)
                break;
            while(temp<n+1){
                v.push_back('\0');
                temp++;
            }
            for(int i=0; i<tasks.size(); i++){
                if(!visited[tasks[i]-'A'] && !completed[tasks[i]-'A']){
                    pq.push({um[tasks[i]],tasks[i]});
                    visited[tasks[i]-'A']=true;
                }
            }
        }
        return v.size();
    }
};