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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            cout<<fast->val<<endl;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast && fast->next==NULL)
            return slow;
        else
            return slow;
    }
};