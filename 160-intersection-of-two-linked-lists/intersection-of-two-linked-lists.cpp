/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode* collision(ListNode* temp1, ListNode*temp2 , int cnt1 , int cnt2){
    //     if(cnt1 == cnt2){
    //         while(temp1 && temp2){
    //             if(temp1 == temp2){
    //                 return temp1;
    //             }
    //             temp1 = temp1->next;
    //             temp2= temp2->next;
    //         }
    //         return NULL;
    //     }
    //     else if(cnt1>cnt2){
    //         for(int i =0; i<cnt1-cnt2; i++){
    //             temp1 = temp1->next;
    //         }
    //          while(temp1 && temp2){
    //             if(temp1 == temp2){
    //                 return temp1;
    //             }
    //             temp1 = temp1->next;
    //             temp2= temp2->next;
    //         }
    //         return NULL;
    //     }
    //     else {
    //         for(int i =0; i<cnt2-cnt1; i++){
    //             temp2 = temp2->next;
    //         }

    //         while(temp1 && temp2){
    //             if(temp1 == temp2){
    //                 return temp1;
    //             }
    //             temp1 = temp1->next;
    //             temp2= temp2->next;
    //         }
    //         return NULL;
    //     }

    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode*temp2 = headB;
        // int cnt1=0;
        // int cnt2=0;
        // while(temp1!= NULL){
        //     cnt1++;
        //     temp1 = temp1->next;
        // }
        // while(temp2!= NULL){
        //     cnt2++;
        //     temp2 = temp2->next;
        // }
        // temp1 = headA;
        // temp2 = headB;
        // return collision(temp1, temp2 , cnt1, cnt2);
        if(headA == NULL || headB == NULL) return NULL;
        while(temp1!=temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1 == temp2) return temp1;
            if(temp1== NULL) temp1 = headB;
            if(temp2== NULL) temp2 = headA;
        }
        return temp1;
    }
};