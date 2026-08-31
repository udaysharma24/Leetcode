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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* cur=head;
        int count=0;
        while(cur!=NULL){
            count++;
            cur=cur->next;
        }
        if(count<4)
            return {-1,-1};
        vector<int> maxmin_index;
        int index=1;
        ListNode* prev=head;
        cur=head->next;
        ListNode* lat=cur->next;
        while(lat!=NULL){
            if(cur->val>prev->val && cur->val>lat->val)
                maxmin_index.push_back(index);
            else if(cur->val<prev->val && cur->val<lat->val)
                maxmin_index.push_back(index);
            prev=prev->next;
            cur=cur->next;
            lat=lat->next;
            index++;
        }
        if(maxmin_index.size()<2)
            return {-1,-1};
        int mindistance=INT_MAX;
        for(int i=1; i<maxmin_index.size(); i++){
            mindistance=min(mindistance,maxmin_index[i]-maxmin_index[i-1]);
        }
        int maxdistance=maxmin_index[maxmin_index.size()-1]-maxmin_index[0];
        return {mindistance,maxdistance};
    }
};