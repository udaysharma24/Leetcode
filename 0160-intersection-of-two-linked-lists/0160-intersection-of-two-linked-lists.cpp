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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        unordered_map<ListNode*,int> um;
        while(temp1!=NULL)
        {
            um[temp1]++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            if(um[temp2]==1)
                return temp2;
            temp2=temp2->next;
        }
        return nullptr;
    }
};