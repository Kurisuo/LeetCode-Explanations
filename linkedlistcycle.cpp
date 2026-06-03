//LeetCode 141 Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        
        ListNode* pntr_ahead = head;
        ListNode* pntr_behind = head;

        while(pntr_ahead != nullptr && pntr_ahead -> next != nullptr){ //In case there is no cycle
            
            pntr_ahead = pntr_ahead -> next -> next; //if there is a cycle, pointer will loop around and catch up to pntr_behind
            pntr_behind = pntr_behind -> next;

            if(pntr_ahead == pntr_behind){ 
                return true;
            }
        }
        return false; 
    }
};