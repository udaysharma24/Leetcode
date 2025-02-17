class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> v;
        int mx1=*max_element(mat[0].begin(),mat[0].end());
        int uindex=0;
        for(int j=0; j<mat[0].size(); j++)
        {
            if(mat[0][j]==mx1)
                uindex=j;
        }

        if(mat.size()==1)
        {
            v.push_back(0);
            v.push_back(uindex);
            return v;
        }

        if(mat[0][uindex]>mat[1][uindex])
        {
            v.push_back(0);
            v.push_back(uindex);
            return v;
        }

        int mx2=*max_element(mat[mat.size()-1].begin(),mat[mat.size()-1].end());
        int lindex=0;
        for(int j=0; j<mat[0].size(); j++)
        {
            if(mat[mat.size()-1][j]==mx2)
                lindex=j;
        }
        if(mat[mat.size()-1][lindex]>mat[mat.size()-2][lindex])
        {
            v.push_back(mat.size()-1);
            v.push_back(lindex);
            return v;
        }

        for(int i=1; i<mat.size()-1; i++)
        {
            int low=1;
            int high=mat[0].size();
            int mid=(low+high)/2;
            while(low<=high)
            {
                if((mat[i][mid]>mat[i-1][mid]) && (mat[i][mid]>mat[i+1][mid]) && (mat[i][mid]>mat[i][mid-1]) && (mat[i][mid]>mat[i][mid+1]))
                {
                    v.push_back(i);
                    v.push_back(mid);
                    return v;
                }
                else if(mat[i][mid]>mat[i][mid-1])
                {
                    low=mid+1;
                    mid=(low+high)/2;
                }
                else if(mat[i][mid]>mat[i][mid+1])
                {
                    high=mid-1;
                    mid=(low+high)/2;
                }
            }
        }
        return v;
    }
};