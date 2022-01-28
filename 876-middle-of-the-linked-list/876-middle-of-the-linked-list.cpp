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
    ListNode *l;
    ListNode* middleNode(ListNode* head) {
        int i=0,n=countNodes(head);
        
        while(i!=n/2)
        {
            i++;
            head=head->next;
        }
        while(head!=NULL)
        {
            insertAtEnd(head->val);
            head=head->next;
        }
            
        return l;
    }
    
    int countNodes(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    
    
void insertAtEnd(int val)
{
    struct ListNode *n = new ListNode(val);
    struct ListNode *r = l;
    if (l== NULL)
    {
        l=n;
        return;
    }
    while (r->next != NULL)
    {
        r = r->next;
    }
    r->next = n;
}
    
};