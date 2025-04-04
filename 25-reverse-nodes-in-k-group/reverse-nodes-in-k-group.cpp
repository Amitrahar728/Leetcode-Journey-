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
    ListNode* reverse(ListNode* head){
    ListNode* temp = head;  
   
 
    ListNode* prev = NULL;  
    while(temp != NULL){ 
       ListNode* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front; 
    }
   
    return prev;  
    }

    ListNode* kvalue(ListNode* temp, int k ){
            k-=1;
            while(temp != NULL && k>0){
                k--;
                temp = temp->next;
            }
            return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;  
ListNode* prevLast = NULL;  

while (temp != NULL) {  
    ListNode* kThNode = kvalue(temp, k);  

    if (kThNode == NULL) {  
        if (prevLast) prevLast->next = temp;  
        break;  
    }  

    ListNode* nextNode = kThNode->next;  
    kThNode->next = NULL;  
    reverse(temp);  

    if (temp == head) {  
        head = kThNode;  
    } else {  
        prevLast->next = kThNode;  
    }  

    prevLast = temp;  
    temp = nextNode;  
}  

return head;  

    }
};