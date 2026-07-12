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
        vector<int>x;
        if(lists.size()==0)return nullptr;
        for(auto& i:lists){
            ListNode* temp=i;
            while(i){
                x.push_back(i->val);
                i=i->next;
            }
        }
        sort(x.begin(),x.end());
        ListNode* temp=new ListNode(x[0]);
        ListNode* mover=temp;
        for(int i=1;i<x.size();i++){
            mover->next=new ListNode(x[i]);
            mover=mover->next;
        }
        return temp;
    }
};
