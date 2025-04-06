class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            
            int val = temp->val;
            temp->val = temp->next->val;
            temp->next->val = val;

            temp = temp->next->next;
        }

        return head;
    }
};
