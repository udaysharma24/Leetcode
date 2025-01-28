class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v;
        for(int i=0; i<2000; i++)
        {
            if(lower_bound(arr.begin(),arr.end(),(i+1))==arr.end() || *lower_bound(arr.begin(),arr.end(),(i+1))!=(i+1))
                v.push_back(i+1);
        }
        cout<<v.size();
        return v[k-1];
    }
};