class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        if(s.empty())
            return 0;
        sort(s.begin(), s.end(), greater<int>());   
        int cnt=0;
        int j=0;
        for(int i=0; i<g.size(); i++)
        {
            if(g[i]<=s[j])
            {
                cnt++;
                j++;
            }
            if(j==s.size())
                break;
        }
        return cnt;
    }
};