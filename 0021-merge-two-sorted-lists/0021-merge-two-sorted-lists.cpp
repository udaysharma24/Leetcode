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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1= list1;
        ListNode* cur2= list2;
        ListNode* head3;
        ListNode* cur3;
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        if(list1->val<=list2->val)
        {
            head3=list1;
            cur1=cur1->next;
        }
        else
        {
            head3=list2;
            cur2=cur2->next;
        }
        head3->next=NULL;
        cur3=head3;
        while(cur1!=NULL && cur2!=NULL)
        {
            if(cur1->val<=cur2->val)
            {
                cur3->next=cur1;
                cur1=cur1->next;
                cur3=cur3->next;
            }
            else
            {
                cur3->next=cur2;
                cur2=cur2->next;
                cur3=cur3->next;
            }
        }
        while(cur1!=NULL)
        {
            cur3->next=cur1;
            cur1=cur1->next;
            cur3=cur3->next;
        }
        while(cur2!=NULL)
        {
            cur3->next=cur2;
            cur2=cur2->next;
            cur3=cur3->next;
        }
        return head3;
    }
};