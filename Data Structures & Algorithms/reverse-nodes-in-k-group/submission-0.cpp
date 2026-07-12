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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>x;
        ListNode* temp=head;
        while(temp){
            x.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=0;i+k<=x.size();i+=k){
            reverse(x.begin()+i,x.begin()+i+k);
        }
        ListNode* t=new ListNode(x[0]);
        ListNode* mover=t;
        for(int i=1;i<x.size();i++){
            mover->next=new ListNode(x[i]);
            mover=mover->next;
        }
        return t;
    }
};
