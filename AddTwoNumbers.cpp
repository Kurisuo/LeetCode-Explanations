// LeetCode (Medium) 2 : Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      //  ListNode* l1_copy = l1;
      //  ListNode* l2_copy = l2;
        ListNode* retList = new ListNode();
        ListNode* curr = retList;
        ListNode* head = retList;
        int carry = 0;

        while(l2 != nullptr || l1 != nullptr || carry > 0){ 
            int val1 = (l1 != nullptr) ? l1 -> val : 0;
            int val2 = (l2 != nullptr) ? l2 -> val : 0;

            int add = (val1 + val2 + carry);
            int digit = add % 10; //extract rightmost
            carry = add / 10;     //delete rightmost

            curr -> next = new ListNode(digit); 
            curr = curr -> next;
 
            if(l2 != nullptr) l2 = l2 -> next;
            if(l1 != nullptr) l1 = l1 -> next;
        }

        return head -> next;
    }
};