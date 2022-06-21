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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* r11 = list1;
        ListNode* r12 = list1;
        ListNode* r21 = list2;
        ListNode* r22 = list2;
        int count1 = 0;
        int count2 =0;
        
        while(r11!=NULL && count1!=a-1)
        {
            count1++;
            r11=r11->next;
        }
        
        while(r12!=NULL && count2!=b)
        {
            count2++;
            r12=r12->next;
        }
        
        while(r22->next!=NULL)
        {
            r22=r22->next;
        }
        
        r11->next = r21;
        r22->next = r12->next;
        
        
        return list1;
    }
};