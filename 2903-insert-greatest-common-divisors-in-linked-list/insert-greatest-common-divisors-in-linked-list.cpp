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
    int gcd(int a,int b){
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *ptr = head;
        while(ptr->next){
            ListNode* next = ptr -> next;
            ListNode* node = new ListNode(gcd(ptr->val,next->val));
            ptr->next = node;
            node->next = next;
            ptr = next;
        }
        return head;
    }
};