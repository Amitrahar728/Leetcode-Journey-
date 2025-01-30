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
    ListNode* deleteNode(ListNode* head, int x) {
        if (head == NULL) return NULL; 
        
        if (x == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            cnt++;
            if (cnt == x) {
                if (prev != NULL) {
                    prev->next = temp->next;
                    delete temp; 
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL; 

        int cnt = 0;
        ListNode* temp = head;

        while (temp != NULL) { 
            cnt++;
            temp = temp->next;
        }

        int middle = (cnt % 2 == 0) ? (cnt / 2) + 1 : (cnt + 1) / 2;
        return deleteNode(head, middle);
    }

    void print(ListNode* head) { 
        ListNode* temp = head;
        while (temp != NULL) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
