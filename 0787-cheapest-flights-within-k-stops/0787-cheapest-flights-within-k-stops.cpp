class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<tuple<int,int,int>> adj[n];
        for(int i=0; i<flights.size(); i++){
            int sorc=flights[i][0];
            int dest=flights[i][1];
            int fare=flights[i][2];
            adj[sorc].push_back({fare,dest,0});
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> price(n, vector<int>(n, INT_MAX));
        pq.push({0,src,0});
        price[src][0]=0;
        while(!pq.empty()){
            int sorc=get<1>(pq.top());
            int fare=get<0>(pq.top());
            int stops=get<2>(pq.top());
            pq.pop();
            for(int i=0; i<adj[sorc].size(); i++){
                int dest2=get<1>(adj[sorc][i]);
                int fare2=get<0>(adj[sorc][i]);
                int stops2=stops;
                if(dest2!=dst)
                    stops2++;
                if(stops2<=k && fare2+fare<price[dest2][stops2]){
                    price[dest2][stops2]=fare2+fare;
                    pq.push({price[dest2][stops2],dest2,stops2});
                }
            }
        }
        int dst_price=*min_element(price[dst].begin(),price[dst].end());
        if(dst_price==INT_MAX)
            dst_price=-1;
        return dst_price;
    }
};