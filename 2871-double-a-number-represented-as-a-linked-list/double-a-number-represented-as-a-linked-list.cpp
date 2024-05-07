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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *prev=NULL,*curr=head,*temp=NULL;
        while(curr!=NULL){
            temp = curr ->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        head = reverseList(head);
        int c=0;
        ListNode *curr=head,*prev=NULL;
        while(curr){
            int temp = curr->val*2;
            temp+=c;
            c = temp/10;
            curr->val = temp%10;
            prev=curr;
            curr=curr->next;
        }
        if(c>0){
            prev->next = new ListNode(c);
            prev = prev->next;
        }
        head = reverseList(head);
        return head;
    }
};