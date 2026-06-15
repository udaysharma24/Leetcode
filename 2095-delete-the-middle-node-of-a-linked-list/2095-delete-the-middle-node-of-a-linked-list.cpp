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
        ListNode* cur=head;
        int cnt=0;
        while(cur!=NULL){
            cnt++;
            cur=cur->next;
        }
        if(cnt==1)
            return nullptr;
        int half=floor(cnt/2);
        cur=head;
        int temp=0;
        ListNode* prev;
        while(temp<half){
            temp++;
            if(temp==1)
                prev=cur;
            cur=cur->next;
            if(temp>=2)
                prev=prev->next;
        }
        prev->next=cur->next;
        cur->next=NULL;
        delete(cur);
        return head;
    }
};