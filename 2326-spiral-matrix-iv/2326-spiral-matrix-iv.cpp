/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n,-1));
        ListNode* cur=head;
        int left=0;
        int up=0;
        int right=n-1;
        int down=m-1;
        while(up<=down && left<=right){
            for(int j=left; j<=right; j++){
                if(cur==NULL)
                    return ans;
                ans[up][j]=cur->val;
                cur=cur->next;
            }
            up++;
            if(up>down)
                break;
            for(int i=up; i<=down; i++){
                if(cur==NULL)
                    return ans;
                ans[i][right]=cur->val;
                cur=cur->next;
            }
            right--;
            if(left>right)
                break;
            for(int j=right; j>=left; j--){
                if(cur==NULL)
                    return ans;
                ans[down][j]=cur->val;
                cur=cur->next;
            }
            down--;
            if(up>down)
                break;
            for(int i=down; i>=up; i--){
                if(cur==NULL)
                    return ans;
                ans[i][left]=cur->val;
                cur=cur->next;
            }
            left++;
            if(left>right)
                break;
        }
        return ans;
    }
};