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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;

        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* beforetemp = temp;
        while(beforetemp -> next != NULL){
            if(beforetemp->next->val == val){
                beforetemp->next = beforetemp->next->next;

            }
            else{
                beforetemp = beforetemp->next;
            }
        }
        return temp->next;
    }
};