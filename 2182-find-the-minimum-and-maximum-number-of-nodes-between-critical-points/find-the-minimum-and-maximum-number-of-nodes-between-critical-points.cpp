class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};
        
        int firstCriticalPoint = -1, prevCriticalPoint = -1;
        int currentIndex = 0;
        int maxDistance = -1, minDistance = INT_MAX;
        
        ListNode *previousNode = head, *currentNode = head->next;
        
        while(currentNode->next) {
            ListNode *nextNode = currentNode->next;
            
            if((currentNode->val > previousNode->val && currentNode->val > nextNode->val) ||
               (currentNode->val < previousNode->val && currentNode->val < nextNode->val)) {
                   
                if(prevCriticalPoint != -1) {
                    minDistance = min(minDistance, currentIndex - prevCriticalPoint);
                }
                
                if(firstCriticalPoint != -1) {
                    maxDistance = currentIndex - firstCriticalPoint;
                }
                
                if(firstCriticalPoint == -1)
                    firstCriticalPoint = currentIndex;
                    
                prevCriticalPoint = currentIndex;
            }
            
            currentIndex++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        
        if(minDistance == INT_MAX) return {-1, -1};
        return {minDistance, maxDistance};
    }
};
