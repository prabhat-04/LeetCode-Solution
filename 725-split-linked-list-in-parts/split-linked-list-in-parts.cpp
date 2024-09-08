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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        if(!head) return ans;
        int cnt =0;
        ListNode*ptr = head;
        while(ptr){
            cnt++;
            ptr = ptr->next;
        }
        int n = cnt / k;
        int rem = cnt%k;
        ptr = head;
        int i=0;
        while(ptr){
            int temp = n;
            if(rem>0){
                temp++;
                rem--;
            }
            ans[i] = ptr;
            ListNode* prev=NULL;
            while(ptr!=NULL && temp>0){
                prev=ptr;
                ptr = ptr->next;
                temp--;
            }
            if(prev)
                prev->next=NULL;
            i++;
        }
        return ans;
    }
};