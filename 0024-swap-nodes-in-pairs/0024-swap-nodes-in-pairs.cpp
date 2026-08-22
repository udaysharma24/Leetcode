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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur1=head;
        ListNode* cur2;
        ListNode* prev;
        ListNode* later;
        if(cur1!=NULL)
            cur2=cur1->next;
        if(cur1==NULL)
            return head;
        if(cur2!=NULL)
            later=cur2->next;
        if(cur2==NULL)
            return head;
        cur1->next=later;
        cur2->next=cur1;
        head=cur2;
        ListNode* temp=cur1;
        cur1=cur2;
        cur2=temp;
        cur2->next=later;
        while(cur1!=NULL && cur2!=NULL){
            prev=cur2;
            cur1=prev->next;
            if(cur1!=NULL)
                cur2=cur1->next;
            if(cur1==NULL)
                break;
            if(cur2!=NULL)
                later=cur2->next;
            if(cur2==NULL)
                break;
            cur1->next=later;
            cur2->next=cur1;
            prev->next=cur1;
            ListNode* temp=cur1;
            cur1=cur2;
            cur2=temp;
            cur2->next=later;
            prev->next=cur1;
        }
        return head;
    }
};