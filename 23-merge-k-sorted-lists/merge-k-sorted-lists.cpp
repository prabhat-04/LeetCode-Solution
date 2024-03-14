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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }

        // ListNode* ptr,*head ;
        // if(list1->val <=list2->val){
        //     ptr=list1;
        //     head=list1;
        //     list1=list1->next;
        // }
        // else{
        //     ptr=list2;
        //     head=list2;
        //     list2=list2->next;
        // }

        // while(list1 && list2){
        //     if(list1->val <=list2->val){
        //         ptr->next=list1;
        //         list1=list1->next;
        //     }
        //     else{
        //         ptr->next=list2;
        //         list2=list2->next;
        //     }
        //     ptr=ptr->next;
        // }
        // if(list1)
        //     ptr->next=list1;
        // if(list2)
        //     ptr->next=list2;
        // return head;

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode *ans;
        while(lists.size()>1){
            ans = mergeTwoLists(lists[lists.size()-1],lists[lists.size()-2]);
            lists.pop_back();
            lists.pop_back();
            lists.push_back(ans);
        }
        return lists[0];
    }
};