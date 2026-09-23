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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<int,vector<int>,greater<int>>mpq;
        for(auto & i:lists){
            ListNode* temp=i;
            while(temp){
                mpq.push(temp->val);
                temp=temp->next;
            }
        }
        if(mpq.empty())return nullptr;
        ListNode* x=new ListNode(mpq.top());
        mpq.pop();
        ListNode* mover=x;
        while(!mpq.empty()){
            mover->next=new ListNode(mpq.top());
            mover=mover->next;
            mpq.pop();
        }
        return x;
    }
};
