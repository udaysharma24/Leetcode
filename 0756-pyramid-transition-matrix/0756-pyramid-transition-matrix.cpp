class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(string current, unordered_map<string, vector<char>>& um, int curindex, string above){
        string key=current+to_string(curindex)+above;
        if(dp.find(key)!=dp.end())
            return dp[key];
        if(current.length()==1)
            return dp[key]=true;
        else if(curindex==current.length()-1)
            return dp[key]=solve(above,um,0,"");
        else{
            string str1=current.substr(curindex,2);
            if(um.find(str1)==um.end())
                return dp[key]=false;
            else{
                for(int i=0; i<um[str1].size(); i++){
                    above.push_back(um[str1][i]); //Try
                    bool flag=solve(current,um,curindex+1,above); //Explore
                    if(flag==false) //Undo
                        above.pop_back();
                    else
                        return dp[key]=true;
                }
            }
        }
        return dp[key]=false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> um;
        for(int i=0; i<allowed.size(); i++){
            string str1=allowed[i].substr(0,2);
            char ch=allowed[i][2];
            um[str1].push_back(ch);
        }
        bool flag=solve(bottom,um,0,"");
        return flag;
    }
};