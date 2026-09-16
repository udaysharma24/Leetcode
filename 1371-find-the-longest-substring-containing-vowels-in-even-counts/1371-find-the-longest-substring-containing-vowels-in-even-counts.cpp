class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        
        /* 
         * WHY SIZE 32? 
         * We track 5 vowels (a, e, i, o, u). Each vowel can either be ODD (1) or EVEN (0).
         * 5 vowels with 2 possible states each = 2^5 = 32 total possible bitmask configurations.
         * The states range from 00000 (all even) to 11111 (all odd).
         * 
         * WHY INITIALIZE WITH -2?
         * We need a unique placeholder to know if we have visited a state before. 
         * We cannot use -1 because index -1 is explicitly reserved for our base case!
         */
        vector<int> first_seen(32, -2);
        
        /* 
         * THE BASE CASE SHIELD:
         * At the very start (before processing any characters), we have seen 0 vowels.
         * Zero is an even number, so all vowels have an EVEN count.
         * This means the initial mask is 00000 (integer 0).
         * We record that state 0 was first seen at timeline index -1.
         * This ensures that if the entire string from index 0 to i has even vowel counts, 
         * the formula i - first_seen[0] evaluates to i - (-1) = i + 1, capturing the full range.
         */
        first_seen[0] = -1;
        
        int mask = 0;     // Keeps track of the running parity state of all vowels
        int maxlen = 0;   // Stores our global maximum valid substring length
        
        for (int i = 0; i < n; i++) {
            /* 
             * THE TOGGLE MECHANISM (XOR Magic):
             * (1 << X) creates a bitmask with a single '1' at the X-th position.
             * The bitwise XOR operator (^) acts as an odd/even toggle state machine:
             *   - 0 ^ 1 = 1 (Even turns to Odd)
             *   - 1 ^ 1 = 0 (Odd turns back to Even)
             * This completely replaces doing slow arithmetic operations like 'count % 2'.
             */
            if (s[i] == 'a')      
                mask ^= (1 << 0); // Toggles the 0th bit for 'a'
            else if (s[i] == 'e') 
                mask ^= (1 << 1); // Toggles the 1st bit for 'e'
            else if (s[i] == 'i') 
                mask ^= (1 << 2); // Toggles the 2nd bit for 'i'
            else if (s[i] == 'o') 
                mask ^= (1 << 3); // Toggles the 3rd bit for 'o'
            else if (s[i] == 'u') 
                mask ^= (1 << 4); // Toggles the 4th bit for 'u'
            
            /* 
             * FIRST-OCCURRENCE RULE FOR WINDOW MAXIMIZATION:
             * If first_seen[mask] is still -2, it means this exact combination of 
             * odd/even vowel parities has NEVER been encountered before in our prefix trail.
             * We record its position right now. To maximize the future window length, 
             * we WANT this index to stay as small (as far left) as possible. 
             * Thus, if we see this mask again later, we WILL NOT overwrite this original index.
             */
            if (first_seen[mask] == -2) {
                first_seen[mask] = i;
            } 
            /* 
             * THE SUBARRAY MATCH CHECK:
             * If the current mask value has already been recorded (is not -2), it means 
             * the exact same parity configuration existed at some earlier index 'first_seen[mask]'.
             * 
             * If the state flipped back to the exact same configuration, it mathematically 
             * guarantees that every vowel encountered between 'first_seen[mask] + 1' and 'i' 
             * was toggled an even number of times. Even number of toggles = Even count of vowels!
             * 
             * We compute the distance of this window and maximize our global tracking counter.
             */
            else {
                int current_window_length = i - first_seen[mask];
                maxlen = max(maxlen, current_window_length);
            }
        }
        
        return maxlen; // Return the absolute longest valid window found
    }
};
