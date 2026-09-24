class Solution {
    public int lengthLongestPath(String input) {
        // 1. Instantly split the entire string into clean, individual lines
        String[] lines = input.split("\n");
        
        Stack<Integer> stack = new Stack<>();
        int maxLen = 0;
        
        for (String line : lines) {
            /* 
             * 2. FIND THE DEPTH LEVEL:
             * Look for the last occurrence of the tab character '\t'.
             * If there are no tabs, lastIndexOf returns -1.
             * Adding 1 gives us the perfect depth level (0 for root, 1 for subfolder, etc.)
             */
            int depth = line.lastIndexOf("\t") + 1;
            
            // 3. ALIGN THE STACK: Move back to the correct parent folder level
            while (stack.size() > depth) {
                stack.pop();
            }
            
            // 4. CALCULATE CLEAN NAME LENGTH: Total length minus the tab characters
            int nameLen = line.length() - depth;
            
            // 5. COMPUTE CUMULATIVE PATH LENGTH:
            // If the stack is empty, we are at the root level.
            // Otherwise, add the parent folder length plus 1 for the '/' character.
            int parentLen = stack.isEmpty() ? 0 : stack.peek() + 1;
            int currLen = parentLen + nameLen;
            
            // 6. CHECK FILE VS DIRECTORY:
            if (line.contains(".")) {
                // It has a dot, so it's a file! Update our maximum tracker.
                maxLen = Math.max(maxLen, currLen);
            } else {
                // It's a directory! Push its total path length onto the stack.
                stack.push(currLen);
            }
        }
        
        return maxLen;
    }
}