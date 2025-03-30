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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
            return nullptr;
        int total=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            total++;
            temp=temp->next;
        }
        n=total-n+1;
        ListNode* prev=nullptr;
        ListNode* front=head;
        if(n==1)
        {
            prev=head;
            head=prev->next;
            prev->next=nullptr;
            delete prev;
            return head;
        }
        prev=head;
        front=head->next;
        for(int i=2; i<n; i++)
        {
            prev=prev->next;
            front=front->next;
        }
        prev->next=front->next;
        front->next=NULL;
        delete front;
        return head;
    }
};