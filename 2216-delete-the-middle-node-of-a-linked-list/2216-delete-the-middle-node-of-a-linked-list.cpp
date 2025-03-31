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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev=head;
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL)
            return nullptr;
        int i=0;
        while(fast!=NULL)
        {
            if(fast->next==NULL)
            {
                prev->next=slow->next;
                slow->next=nullptr;
                delete slow;
                return head;
            }
            if(i>=1)
                prev=prev->next;
            slow=slow->next;
            fast=fast->next->next;
            i++;
        }
        if(fast==NULL)
        {
            prev->next=slow->next;
            slow->next=nullptr;
            delete slow;
            return head;
        }
        return head;
    }
};