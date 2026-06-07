//LeetCode 3263 Convert Doubly Linked List to Array I

/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *head){
        vector<int>arr;
        Node* pntr = head;
        for(; pntr != nullptr; pntr = pntr -> next){ 
            arr.push_back(pntr -> val);
        }
        return arr;
    }
};