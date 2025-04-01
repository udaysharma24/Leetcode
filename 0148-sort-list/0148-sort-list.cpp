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
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val<=head2->val)
            {
                temp->next=head1;
                temp=temp->next;
                head1=head1->next;
            }
            else
            {
                temp->next=head2;
                temp=temp->next;
                head2=head2->next;
            }
        }
        if(head1)
            temp->next=head1;
        else
            temp->next=head2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid2=slow->next;
        slow->next=nullptr;
        ListNode* lefthead=sortList(head);
        ListNode* righthead=sortList(mid2);
        return merge(lefthead, righthead);
    }
};