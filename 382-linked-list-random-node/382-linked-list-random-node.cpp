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
    ListNode* r;
    Solution(ListNode* head) {
        r=head;
    }
    
    int getRandom() {
        ListNode* t =r;
        vector<int> v;
        while(t!=NULL)
        {
            v.push_back(t->val);
            t=t->next;
        }
        int random = 0 + (rand() % v.size());
        return v[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */