class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        bool flag=false;
        vector<int> v;
        int mx=0;
        for(int i=0; i<intervals.size()-1; i++)
        {
            if(max(mx,intervals[i][1])>=intervals[i+1][0])
            {
                if(flag==false)
                    v.push_back(intervals[i][0]);
                flag=true;
                cout<<"Hi1 ";
                mx=max(mx,intervals[i][1]);
            }
            else if(flag==true)
            {
                v.push_back(max(intervals[i][1],mx));
                ans.push_back(v);
                flag=false;
                v.clear();
                mx=0;
                cout<<"Hi2 ";
            }
            else if(flag==false)
            {
                v.push_back(intervals[i][0]);
                v.push_back(intervals[i][1]);
                ans.push_back(v);
                cout<<"Hi3 ";
                v.clear();
            }
        }
        if(flag==true)
        {
            v.push_back(max(mx,intervals[intervals.size()-1][1]));
            ans.push_back(v);
        }
        else
        {
            v.push_back(intervals[intervals.size()-1][0]);
            v.push_back(intervals[intervals.size()-1][1]);
            ans.push_back(v);
        }
        return ans;
    }
};