class Solution {
public:
    void solve(vector<int>& arr, vector<int>& v, int& ans, vector<bool>& visited){
        if(v.size()==arr.size()){
            ans++;
            return;
        }
        for(int i=0; i<arr.size(); i++){
            if(!visited[i] && ((v.size()+1)%arr[i]==0 || arr[i]%(v.size()+1)==0)){
                v.push_back(arr[i]);
                visited[i]=true;
                solve(arr,v,ans,visited);
                visited[i]=false;
                v.pop_back();
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v;
        vector<int> arr(n);
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++){
            arr[i]=i+1;
        }
        int ans=0;
        solve(arr,v,ans,visited);
        return ans;
    }
};