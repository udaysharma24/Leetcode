class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int i=0; i<arr.size(); i++){
            um[arr[i]]++;
        }
        sort(arr.begin(),arr.end(),[&um](int a, int b){
            if(um[a]==um[b])
                return a<b;
            return um[a]>um[b];
        });
        unordered_set<int> us;
        int ans=0;
        int count=0;
        for(int i=0; i<arr.size(); i++){
            if(us.find(arr[i])==us.end()){
                us.insert(arr[i]);
                count+=um[arr[i]];
                ans++;
            }
            if(2*count>=arr.size())
                break;
        }
        return ans;
    }
};