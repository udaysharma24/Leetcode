class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> um;
        for(int i=0; i<supplies.size(); i++){
            um[supplies[i]]++;
        }
        vector<string> ans;
        vector<bool> visited(recipes.size(),false);
        queue<string> q;
        for(int i=0; i<recipes.size(); i++){
            bool allpresent=true;
            for(int j=0; j<ingredients[i].size(); j++){
                if(um.find(ingredients[i][j])==um.end()){
                    allpresent=false;
                    break;
                }
            }
            if(allpresent && !visited[i]){
                q.push(recipes[i]);
                visited[i]=true;
            }   
        }
        while(!q.empty()){
            string temp=q.front();
            q.pop();
            um[temp]++;
            ans.push_back(temp);
            for(int i=0; i<recipes.size(); i++){
                bool allpresent=true;
                for(int j=0; j<ingredients[i].size(); j++){
                    if(um.find(ingredients[i][j])==um.end()){
                        allpresent=false;
                        break;
                    }
                }
                if(allpresent && !visited[i]){
                    q.push(recipes[i]);
                    visited[i]=true;
                }
            }
        }
        return ans;
    }
};