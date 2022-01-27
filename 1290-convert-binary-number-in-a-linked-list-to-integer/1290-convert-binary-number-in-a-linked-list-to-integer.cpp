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
    int getDecimalValue(ListNode* head) {
        ListNode* r=head;
        int count=lengthLinkedList(head);
        count--;
        int val=0;
        while(r!=NULL)
        {
            val+=(r->val)*pow(2,count);
            count--;
            r=r->next;
        }
        return val;
    }
    
    int lengthLinkedList(ListNode* head)
    {
        ListNode* r=head;
        int count=0;
        while(r!=NULL)
        {
            count++;
            r=r->next;
        }
        return count;
    }
};