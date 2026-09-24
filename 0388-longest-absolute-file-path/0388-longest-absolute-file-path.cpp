class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string line;
        stack<int> st; // Stores cumulative length of parent directories
        int maxlen = 0;
        
        while (getline(ss, line, '\n')) {
            // 1. Calculate depth by counting consecutive tab characters at the front
            int depth = 0;
            while (depth < line.length() && line[depth] == '\t') {
                depth++;
            }
            
            // 2. Adjust stack position to align with current tree depth level
            while (st.size() > depth) {
                st.pop();
            }
            
            // 3. Extract the clean token name (strip away the front tabs)
            string name = line.substr(depth);
            
            // 4. Compute cumulative length from parent directory
            int parent_len = st.empty() ? 0 : st.top();
            int curr_len = parent_len + name.length();
            
            // 5. If it contains a dot, it's a file -> update our global maximum
            if (name.find('.') != string::npos) {
                maxlen = max(maxlen, curr_len);
            } 
            // 6. If it's a directory, push it onto the stack (+1 accounts for the future '/' separator)
            else {
                st.push(curr_len + 1);
            }
        }
        
        return maxlen;
    }
};