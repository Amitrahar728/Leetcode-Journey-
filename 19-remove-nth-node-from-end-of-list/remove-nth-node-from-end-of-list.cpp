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
        ListNode* temp = head;
        int cnt = 0;
        while(temp!= NULL){
            cnt++;
            temp = temp ->next;
        }
        // cnt++;
        if(cnt == n){
            ListNode*newhead = head->next;
            delete head;
            return newhead;
        }
        int x = cnt - n-1;
        // int c = 1;
        temp = head;
        while(x>0){
            
            // if(x==0) break;
            temp = temp->next;
            x--;
        }
        ListNode* del = temp->next;
        temp ->next = temp->next->next;
        delete del;
        return head;

    }
};