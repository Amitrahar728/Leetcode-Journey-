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
    ListNode* middleNode(ListNode* head) {
        int cnt =0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        if(cnt %2 ==0) {
            int k = cnt /2+1;
            int cnt2 =1;
            while(temp!= NULL){
                if(cnt2 == k){
                    return temp;
                }
                cnt2++;
                temp=temp->next;
            }
        }
        else{
            int k = (cnt+1)/2;
            int cnt3 =1;
            while(temp!= NULL){
                if(cnt3 == k){
                    return temp;
                }
                cnt3++;
                temp=temp->next;
            }
        }
        return 0;
    }
};