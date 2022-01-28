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
    ListNode* l;
    
    ListNode* reverseList(ListNode* head) {
        ListNode* r=head;
        
        while(r!=NULL)
        {
            insertAtBegin(r->val);
            r=r->next;
        }
        return l;
    }
    void insertAtBegin(int val)
    {
        struct ListNode *n = new ListNode(val);
        n->next = l;
        l = n;
    }
};