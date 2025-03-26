/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        unordered_map<ListNode *, int> m;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
                break;
        }
        if(fast->next==NULL || fast->next->next==NULL)
            return nullptr;
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            if(m[temp]==1)
                return temp;
            m[temp]++;
            temp=temp->next;
        }
        return nullptr;
    }
};