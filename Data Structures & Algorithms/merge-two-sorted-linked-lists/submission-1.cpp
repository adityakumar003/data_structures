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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>x;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        if(temp1==nullptr && temp2==nullptr)return nullptr;
        while(temp1){
            x.push_back(temp1->val);
            temp1=temp1->next;
        }
        while(temp2){
            x.push_back(temp2->val);
            temp2=temp2->next;
        }
        sort(x.begin(),x.end());
        ListNode* head=new ListNode(x[0]);
        ListNode* mover=head;
        for(int i=1;i<x.size();i++){
            mover->next=new ListNode(x[i]);
            mover=mover->next;
        }
        return head;
    }
};
