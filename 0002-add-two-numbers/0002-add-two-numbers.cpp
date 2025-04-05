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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head=new ListNode((temp1->val)+(temp2->val));
        head->next=NULL;
        temp1=temp1->next;
        temp2=temp2->next;
        ListNode* temp=head;
        int carry=0;
        if(head->val>=10)
        {
            carry=1;
            head->val=(head->val)%10;
        }
        while(temp1!=NULL && temp2!=NULL)
        {
            ListNode* newnode = new ListNode((temp1->val)+(temp2->val)+carry);
            newnode->next=NULL;
            carry=(newnode->val)/10;
            newnode->val=(newnode->val)%10;
            temp1=temp1->next;
            temp2=temp2->next;
            temp->next=newnode;
            temp=newnode;
        }
        while(temp1!=NULL)
        {
            ListNode* newnode = new ListNode((temp1->val)+carry);
            newnode->next=NULL;
            carry=(newnode->val)/10;
            newnode->val=(newnode->val)%10;
            temp1=temp1->next;
            temp->next=newnode;
            temp=newnode;
        }
        while(temp2!=NULL)
        {
            ListNode* newnode = new ListNode((temp2->val)+carry);
            newnode->next=NULL;
            carry=(newnode->val)/10;
            newnode->val=(newnode->val)%10;
            temp2=temp2->next;
            temp->next=newnode;
            temp=newnode;
        }
        if(carry!=0)
        {
            ListNode* newnode= new ListNode(carry);
            newnode->next=NULL;
            temp->next=newnode;
            temp=newnode;
        }
        return head;
    }
};