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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr_a=NULL,*curr_b;
        ListNode*ptr=list1;
        int cnt=0;
        while(cnt<a-1 && ptr){
            cnt++;
            ptr=ptr->next;
        }
        curr_a=ptr;
        // cout<<curr_a->val<<endl;
        while(cnt<b && ptr){
            cnt++;
            ptr=ptr->next;
        }
        curr_b= ptr;
        // cout<<curr_b->val<<endl;
        ptr=list2;
        while(ptr->next){
            ptr=ptr->next;
        }
        // cout<<ptr->val<<endl;
        curr_a->next=list2;
        ptr->next=curr_b->next;
        return list1;
    }
};