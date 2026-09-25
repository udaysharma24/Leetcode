class Solution {
public:
    void solve(int index, string digits, vector<string>& mapping, string s, vector<string>& ans){
        if(index==digits.length()){
            ans.push_back(s);
            return;
        }
        else{
            int key=digits[index]-48;
            for(int i=0; i<mapping[key].length(); i++){
                solve(index+1,digits,mapping,s+mapping[key][i],ans);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s="";
        vector<string> mapping(10,"");
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        solve(0,digits,mapping,s,ans);
        return ans;
    }
};