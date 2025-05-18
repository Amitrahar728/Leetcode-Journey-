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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;

        for (auto node : lists) {
            if (node != nullptr) {
                heap.push(node);
            }
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!heap.empty()) {
            ListNode* temp = heap.top();
            heap.pop();

            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }

            if (temp->next != nullptr) {
                heap.push(temp->next);
            }
        }

        return head;
    }
};
