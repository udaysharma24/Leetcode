class Solution {
public:
    void solve(int startnum, int n, vector<int>& v){
        int cur=startnum;
        if(cur<=n)
            v.push_back(cur);
        else
            return;
        for(int i = 0; i <= 9; i++){
            int next = cur*10+i;
            if(next>n)
                break;
            solve(next,n,v);
        }
    }
    vector<int> lexicalOrder(int n) {
        // 1st Method: Using Min-heap
        // priority_queue<string, vector<string>, greater<string>> pq;
        // vector<int> ans;
        // for(int i=1; i<=n; i++){
        //     pq.push(to_string(i));
        // }
        // while(!pq.empty()){
        //     ans.push_back(stoi(pq.top()));
        //     pq.pop();
        // }
        // return ans;

        //2nd method: Using Recursive DFS
        vector<int> v;
        for(int i=1; i<=9; i++){
            solve(i,n,v);
        }
        return v;
    }
};