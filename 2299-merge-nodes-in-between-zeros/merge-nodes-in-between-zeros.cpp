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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
        ListNode * ptr = head->next,*prev=NULL;
        int sum=0;
        while(ptr){
            if(ptr->val!=0){
                sum+=ptr->val;
            }
            else{
                if(!prev){
                    head = new ListNode(sum);
                    prev = head;
                    sum=0;
                }
                else{
                    ListNode * newNode = new ListNode(sum);
                    sum=0;
                    prev->next = newNode;
                    prev=newNode;
                }
            }
            ptr = ptr->next;
        }
        prev->next=NULL;
        return head;
    }
};