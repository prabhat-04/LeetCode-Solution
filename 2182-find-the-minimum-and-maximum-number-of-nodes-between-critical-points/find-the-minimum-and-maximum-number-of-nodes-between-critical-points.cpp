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
        if(!head || !head->next || !head->next->next) return {-1,-1};
        int first=-1,prev=-1;
        int index=0;
        int maxDis=-1,minDis=INT_MAX;
        ListNode *pre=head,*ptr=head->next;
        while(ptr->next){
            ListNode *next = ptr->next;
            if((ptr->val > pre->val && ptr->val > next->val)||(ptr->val < pre->val && ptr->val < next->val)){
                if(prev!=-1){
                    minDis = min(minDis,index-prev);
                }
                if(first!=-1){
                    maxDis = index - first;
                }
                if(first==-1)
                    first=index;
                prev = index;
            }
            index++;
            pre = ptr;
            ptr = ptr->next;
        }
        if(minDis==INT_MAX) return {-1,-1};
        return {minDis,maxDis};

    }
};