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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res;
        ListNode* temp = head->next;
        ListNode* prev = head;
        ListNode* nexti = temp->next;
        int count = 1;
        
        while(nexti!=NULL){
            if(temp->val> prev->val && temp->val>nexti->val  || temp->val< prev->val && temp->val<nexti->val){
                res.push_back(count);
            }
            
            count++;
            prev = temp;
            temp = nexti;
            nexti = nexti->next;

        }

        
        if(res.size()<2){
            return {-1,-1};
        }
        
        int mini = INT_MAX;
        int maxi = res.back() - res.front();

        for(int i = 1; i < res.size(); i++) {
            mini = min(mini, res[i] - res[i-1]);
        }

        return {mini, maxi};
    }
};