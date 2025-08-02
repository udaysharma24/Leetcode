class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans((code.size()), 0);
        if(k==0)
        {
            for(int i=0; i<code.size(); i++)
            {
                ans[i]=0;
            }
        }
        else if(k<0)
        {
            k=-k;
            for(int i=0; i<code.size(); i++)
            {
                for(int j=1; j<=k; j++)
                {
                    if((i-j)<0)
                    {
                        int index= (i-j+(code.size()));
                        ans[i]+=code[index];
                    }
                    else
                    {
                        int index= i-j;
                        ans[i]+=code[index];
                    }
                }
            }
        }
        else if(k>0)
        {
            for(int i=0; i<code.size(); i++)
            {
                for(int j=1; j<=k; j++)
                {
                    if((i+j)>=code.size())
                    {
                        int index= (i+j-code.size());
                        ans[i]+=code[index];
                    }
                    else
                    {
                        int index= i+j;
                        ans[i]+=code[index];
                    }
                }
            }
        }
        return ans;
    }
};