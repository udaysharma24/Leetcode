class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needed_rights = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // SNEAKY EDGE CASE: If we need an odd number of right parentheses,
                // it means a lonely ')' is sitting there. Since a new '(' is starting,
                // that lonely ')' can never find a consecutive partner. Fix it immediately!
                if (needed_rights % 2 != 0) {
                    insertions++;     // Insert 1 closing ')' to fix the old pair
                    needed_rights--;  // One less right parenthesis needed now
                }
                needed_rights += 2;   // Each new '(' requires two ')'
            } 
            else { // s[i] == ')'
                // Check if the next character forms a consecutive pair '))'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Successfully found a pair, consume the next ')' safely
                } else {
                    insertions++; // Lonely ')', we must insert 1 missing ')' to make it a pair
                }
                
                needed_rights -= 2; // A valid pair '))' satisfies 2 needed rights
                
                // If we have closing pairs but no opening '(', insert a '(' to balance them
                if (needed_rights < 0) {
                    insertions++;       // Insert 1 opening '('
                    needed_rights += 2; // Balancing out the negative debt
                }
            }
        }
        
        // Any remaining needed_rights at the end must be supplied by adding missing ')'
        return insertions + needed_rights;
    }
};