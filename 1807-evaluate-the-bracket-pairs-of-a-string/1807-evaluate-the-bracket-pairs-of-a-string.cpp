class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> um;

        int n = knowledge.size();

        for(int i = 0; i < n; i++) {
            um[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {

                string str = "";
                i++;

                while(s[i] != ')') {
                    str.push_back(s[i]);
                    i++;
                }

                if(um.find(str) != um.end())
                    ans += um[str];
                else
                    ans += "?";
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};