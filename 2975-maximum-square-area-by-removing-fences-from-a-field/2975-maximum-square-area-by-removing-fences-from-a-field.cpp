class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int MOD=1e9+7;
        long long int ans;
        if(m==n){
            ans=(m-1)*(n-1);
            ans%=MOD;
            return int(ans);
        }
        else{
            hFences.push_back(1);
            hFences.push_back(m);
            vFences.push_back(1);
            vFences.push_back(n);
            sort(hFences.begin(),hFences.end(),greater<int>());
            sort(vFences.begin(),vFences.end(),greater<int>());
            long long int maxans=-1;
            unordered_map<int,int> um;
            for(int i=0; i<vFences.size(); i++){
                for(int j=i+1; j<vFences.size(); j++){
                    um[vFences[i]-vFences[j]]++;
                }
            }
            for(int i=0; i<hFences.size(); i++){
                for(int j=i+1; j<hFences.size(); j++){
                    if(um[hFences[i]-hFences[j]]>0)
                        maxans=max(maxans,((long long)(hFences[i]-hFences[j])*(long long)(hFences[i]-hFences[j])));
                }
            }
            return int(maxans%MOD);
        }
    }
};