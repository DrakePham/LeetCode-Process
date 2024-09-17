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
    int isOverTen = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2 && isOverTen != 0) return new ListNode(1);
        else if (!l1 && !l2 && isOverTen == 0) return nullptr; 
        int l1Val = (l1) ? l1->val : 0;
        int l2Val = (l2) ? l2->val : 0;
        ListNode* curNode = new ListNode();
        
        curNode -> val = l1Val + l2Val + isOverTen;
        isOverTen = curNode -> val / 10;
        curNode -> val %=10;
        if(l1 && l2) curNode->next = addTwoNumbers(l1->next, l2->next);
        else if (l1 && !l2) curNode->next = addTwoNumbers(l1->next, nullptr);
        else if (!l1 && l2) curNode->next = addTwoNumbers(nullptr, l2->next);
        
            
        return curNode;
    }
};