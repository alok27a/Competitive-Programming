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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newnode=new ListNode;
        ListNode* r1=newnode;
        ListNode* r=head;
        if(head==NULL)
            return NULL;
        
        
        while(r!=NULL)
        {
            if(r->val!=val)
            {
                if(newnode==NULL)
                {
                    newnode=new ListNode(r->val);
                }
                else
                {
                    ListNode* t = new ListNode(r->val);
                    newnode->next=t;
                    newnode=newnode->next;
                }
            
            }
            r=r->next;
        }
        r1=r1->next;
        return r1;
    }
};