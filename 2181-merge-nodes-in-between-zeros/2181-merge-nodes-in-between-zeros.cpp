class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *merged = new ListNode(0, nullptr);
        ListNode *mergedTail = merged;
        
        ListNode *tail = head;
        
        int sum = 0;
        while(tail != nullptr){
            if(tail->val == 0 && sum != 0){
                mergedTail->next = new ListNode(sum, nullptr);
                
                mergedTail = mergedTail->next;
                
                sum = 0;    // reset
            }
            
            else sum += tail->val;
            
            tail = tail->next;
        }
        
        return merged->next;
    }
};