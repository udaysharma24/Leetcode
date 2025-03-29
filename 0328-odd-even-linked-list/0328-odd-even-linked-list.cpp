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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* odd=head->next->next;
        ListNode* even=head->next;
        ListNode* tempo=head;
        ListNode* tempe=even;
        while(odd!=NULL)
        {
            tempo->next=odd;
            tempe->next=odd->next;
            if(odd->next==NULL || odd->next->next==NULL)
            {
                tempo=odd;
                tempe=odd->next;
                break;
            }
            odd=odd->next->next;
            tempo=tempo->next;
            tempe=tempe->next;
        }
        tempo->next=even;
        return head;
    }
};