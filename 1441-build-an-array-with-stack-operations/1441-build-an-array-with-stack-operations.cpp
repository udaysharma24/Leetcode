class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int siz=target.size();
        vector<int> stack;
        if(target[0]-1>0)
            stack.push_back((target[0]-1)*2);
        stack.push_back(1);
        for(int i=1; i<siz; i++){
            if(target[i]-target[i-1]-1>0)
                stack.push_back((target[i]-target[i-1]-1)*2);
            stack.push_back(1);
        }
        vector<string> ans;
        for(int i=0; i<stack.size(); i++){
            if(stack[i]>0 && stack[i]%2==0){
                while(stack[i]>0){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    stack[i]-=2;
                }
            }
            else
                ans.push_back("Push");
        }
        return ans;
    }
};