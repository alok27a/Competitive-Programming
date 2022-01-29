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
    ListNode* deleteMiddle(ListNode* head1) {
        int i=0,n=lengthLinkedList(head1);
        ListNode* r= head1;
        ListNode* prev;
        
        if(head1==NULL)
            return head1;
        if(n==1)
            return NULL;
        
        while(i!=(n/2))
        {
            i++;
            prev=r;
            r=r->next;
        }
        cout<<r->val;
        prev->next=r->next;
        return head1;
    }
    
    int lengthLinkedList(ListNode* head1)
    {
        int count=0;
        
        while(head1!=NULL)
        {
            count++;
            head1=head1->next;
        }
        return count;
    }
};