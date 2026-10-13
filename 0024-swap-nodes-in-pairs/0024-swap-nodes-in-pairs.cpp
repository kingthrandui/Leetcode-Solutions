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
// class Solution {
// public:
//     ListNode* swap(ListNode* head){
//         ListNode* temp = head; 
//         ListNode* prev = NULL; 
//         ListNode* nex = head->next;
//         int i = 0;
//         while(temp!=NULL && temp->next!=NULL){
//             if(i%2==0){
//                 // swap(temp->val,temp->next->val);
//                 int n = temp->val;
//                 int m = temp->next->val;
//                 temp->val = m;
//                 temp->next->val = n;
//             }
//             i=i+2;
//             temp = temp->next->next;
//         }
//         return head;
//     }
//     ListNode* swapPairs(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         ListNode* temp = swap(head);
//         return temp;
        
//     }
// };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next != NULL && prev->next->next != NULL) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        return dummy.next;
    }
};