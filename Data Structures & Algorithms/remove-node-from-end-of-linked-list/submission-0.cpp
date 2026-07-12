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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n){
            ListNode* del=head;
            head=head->next;
            delete(del);
            return head;
        }
        temp=head;
        int x=cnt-n-1;
        while(x>0){
            temp=temp->next;
            x--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
