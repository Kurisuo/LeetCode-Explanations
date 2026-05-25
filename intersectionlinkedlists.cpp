/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// LeetCode 160 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        auto* a = headA;
        auto* b = headB;


        while ((a != b )) { 
            
            if(a  == nullptr){ 
                a = headB;
            } 
            else{ a = a -> next;}
            
            if(b  == nullptr){ 
                b = headA;
            } 
            else{ b = b -> next;}
        }       
        

        return a;
    }
};