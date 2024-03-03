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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int count =0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int i=0;
        count = count - n;
        temp=head;
        if(count==0){
            head = head -> next;
            delete temp;
            return head;
        }
        
        while(i<count-1){
            temp=temp->next;
            i++;
        }
        
        ListNode *x = temp->next;
        temp->next=x->next;
        delete x;
        return head;
    }
};