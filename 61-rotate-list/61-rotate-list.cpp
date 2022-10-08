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
    ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next)
        return head;
    ListNode* ptr = head;
    int len = 1;
    while(ptr->next)
    {
        len++;
        ptr = ptr->next;
    }
    if(len==k || k==0)
        return head;
    k = k%len;
    k = len-k;
    ptr->next = head;
    ListNode *dummy;
    while(k>1)
    {
        head = head->next;
        k--;
    }
    dummy = head->next;
    head->next = NULL;
    return dummy;
    
}
};