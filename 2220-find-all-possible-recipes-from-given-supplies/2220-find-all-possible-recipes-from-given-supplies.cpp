class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> result;
        unordered_set<string> s(supplies.begin(),supplies.end());
        bool flag1=true;
        while(flag1==true)
        {
            flag1=false;
            for(int i=0; i<recipes.size(); i++)
            {
                if(s.count(recipes[i])==1)
                    continue;
                bool flag2=true;
                for(int j=0; j<ingredients[i].size(); j++)
                {
                    if(s.count(ingredients[i][j])==0)
                    {
                        flag2=false;
                        break;
                    }
                }
                if(flag2==true)
                {
                    s.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    flag1=true;
                    break;
                }
            }
        }
        return result;
    }
};