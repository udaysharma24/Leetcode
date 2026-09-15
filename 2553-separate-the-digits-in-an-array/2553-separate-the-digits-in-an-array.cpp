class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        for(int i=0; i<nums.size(); i++){
            string s=to_string(nums[i]);
            for(int j=0; j<s.length(); j++){
                string str{s[j]};
                int d=stoi(str);
                digits.push_back(d);
            }
        }
        return digits;
    }
};