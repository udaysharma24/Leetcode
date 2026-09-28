class Solution {
public:
    bool canTransform(string start, string result) {
        unordered_map<char,int> um1;
        unordered_map<char,int> um2;
        for(int i=0; i<start.length(); i++){
            um1[start[i]]++;
        }
        for(int i=0; i<result.length(); i++){
            um2[result[i]]++;
        }
        if(um1['L']!=um2['L'] || um1['R']!=um2['R'] || um1['X']!=um2['X'])
            return false;
        else{
            string s1="";
            string s2="";
            for(int i=0; i<start.length(); i++){
                if(start[i]!='X')
                    s1.push_back(start[i]);
                if(result[i]!='X')
                    s2.push_back(result[i]);
            }
            if(s1!=s2)
                return false;
            else{
                int i = 0;
                int j = 0;

                while(i < start.length() && j < result.length()) {

                    // Skip X in start
                    while(i < start.length() && start[i] == 'X')
                        i++;

                    // Skip X in result
                    while(j < result.length() && result[j] == 'X')
                        j++;

                    // If both reached end
                    if(i == start.length() && j == result.length())
                        return true;

                    // One reached end but other didn't
                    if(i == start.length() || j == result.length())
                        return false;

                    // Corresponding characters must be same
                    if(start[i] != result[j])
                        return false;

                    // L can only move LEFT
                    if(start[i] == 'L' && i < j)
                        return false;

                    // R can only move RIGHT
                    if(start[i] == 'R' && i > j)
                        return false;

                    i++;
                    j++;
                }
            }
        }
        return true;
    }
};