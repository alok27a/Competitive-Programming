/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* r = head;
        ListNode* slow_pt = head;
        ListNode* fast_pt = head;
        int check = 0;
        
        while(fast_pt!=NULL && fast_pt->next!=NULL)
        {
            slow_pt = slow_pt->next;
            fast_pt = fast_pt->next->next;
            if(slow_pt == fast_pt)
            {
                check = 1;
                break;
            }
        }
        if(check == 0)
            return NULL;
        
        slow_pt = head;
        while(slow_pt != fast_pt)
        {
            slow_pt = slow_pt->next;
            fast_pt = fast_pt->next;
        }
        
        return slow_pt;
    }
};