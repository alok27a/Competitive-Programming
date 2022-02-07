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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer,node;
        ListNode* r=head;
        
        while(r!=NULL)
        {
            node.push_back(r->val);
            r=r->next;
        }
        stack<int> s;
        int n=node.size();
        
        s.push(node[n-1]);
        answer.push_back(0);
      
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && s.top()<=node[i])
                s.pop();
            int mg = s.empty() ? 0 : s.top();
            answer.push_back(mg);
            s.push(node[i]);
        }
        reverse(answer.begin(), answer.end());
        return answer;       
    }
};