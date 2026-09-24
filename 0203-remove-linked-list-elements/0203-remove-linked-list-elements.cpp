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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return nullptr;
        while(head!=NULL && head->val==val)
            head=head->next;
        if(head==NULL)
            return nullptr;
        ListNode* prev=head;
        ListNode* cur=prev->next;
        while(cur!=NULL){
            while(cur!=NULL && cur->val==val){
                prev->next=cur->next;
                cur=cur->next;
            }
            prev=prev->next;
            if(cur!=NULL)
                cur=cur->next;
        }
        return head;
    }
};