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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        stack<ListNode*> s;
        ListNode*slow = head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *ptr=slow->next;
        slow->next=NULL;
        while(ptr!=NULL){
            s.push(ptr);
            ptr=ptr->next;
        }
        ptr = head;
        while(!s.empty()){
            s.top()->next = ptr->next;
            ptr->next = s.top();
            s.pop();
            ptr=ptr->next->next;
        }
        return;
    }
};