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
    ListNode* reverseLinkedList(ListNode *head)
    {
        ListNode* temp = head;  
        ListNode* prev = NULL;  
        while(temp != NULL)
        {  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
        return prev;  
    }
    ListNode* kthnode(ListNode* temp, int k)
    {
        k--;
        while(temp!=NULL && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevtail=NULL;
        while(temp!=NULL)
        {
            ListNode* knode=kthnode(temp,k);
            if(knode==NULL)
            {
                if(prevtail)
                {
                    prevtail->next=temp;
                    break;
                }
            }
            ListNode* nextnode=knode->next;
            knode->next=NULL;
            reverseLinkedList(temp);
            if(temp==head)
                head=knode;
            else
                prevtail->next=knode;
            prevtail=temp;
            temp=nextnode;
        }
        return head;
    }
};