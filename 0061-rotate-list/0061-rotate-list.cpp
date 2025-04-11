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
    ListNode* last_to_first(ListNode* head)
    {
        ListNode* temp=head->next;
        ListNode* prev=head;
        while(temp->next!=NULL)
        {
            prev=prev->next;
            temp=temp->next;
        }
        prev->next=NULL;
        temp->next=head;
        head=temp;
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL || head->next==NULL)
            return head;
        ListNode* temp=head;
        long long int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        k=k%cnt;
        while(k)
        {
            head=last_to_first(head);
            k--;
        }
        return head;
    }
};