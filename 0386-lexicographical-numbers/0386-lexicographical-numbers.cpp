class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string, vector<string>, greater<string>> pq;
        vector<int> ans;
        for(int i=1; i<=n; i++){
            pq.push(to_string(i));
        }
        while(!pq.empty()){
            ans.push_back(stoi(pq.top()));
            pq.pop();
        }
        return ans;
    }
};