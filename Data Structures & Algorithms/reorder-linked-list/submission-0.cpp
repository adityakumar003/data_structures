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
    void reorderList(ListNode* head) {
        if(!head) return;

        vector<int> x;
        ListNode* temp = head;

        while(temp){
            x.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ans;
        int i = 0, j = x.size() - 1;

        while(i <= j){
            if(i == j)
                ans.push_back(x[i]);
            else{
                ans.push_back(x[i]);
                ans.push_back(x[j]);
            }
            i++;
            j--;
        }

        temp = head;
        for(int v : ans){
            temp->val = v;
            temp = temp->next;
        }
    }
};
