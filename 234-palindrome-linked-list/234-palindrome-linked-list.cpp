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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        int i,flag=0,n=0;
        
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
            n++;
        }
        if(n==1)
            return true;
        for(i=0;i<n/2;i++)
        {
            if(v[i]!=v[n-i-1])
            {
                flag=0;
                break;}
            else
            {
                flag=1;
            }
        }
        if(flag==0)
            return false;
        return true;
    }
};