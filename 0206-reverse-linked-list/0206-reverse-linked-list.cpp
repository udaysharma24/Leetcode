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
    ListNode* reverseList(ListNode* head) {
        int cnt=0;
        ListNode* tail=head;
        vector<int> v;
        while(tail!=NULL)
        {
            cnt++;
            v.push_back(tail->val);
            tail=tail->next;
        }
        reverse(v.begin(),v.end());
        ListNode* temp=head;
        for(int i=0; i<cnt; i++)
        {
            temp->val=v[i];
            temp=temp->next;
        }
        return head;
    }
};