class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count =0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        ListNode* node1 = head;
        ListNode* node2 = head;
        int j =count-k+1;
       for(int i=1;i<k;i++){
            node1=node1->next;
       }
        for(int i=1;i<j;i++){
            node2=node2->next;
       }
        int help = node1->val;
        node1->val = node2->val;
        node2->val = help;
    
        return head;
    }
};