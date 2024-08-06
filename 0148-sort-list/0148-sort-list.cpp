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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        ListNode* temp ;
        vector<int> listNode;
        list(head, listNode);
        sort(listNode.begin(), listNode.end());
        int length = listNode.size();
        ListNode* result = new ListNode(0);
        temp = result;
        for(int i = 0 ; i < length; i++){
            ListNode* tempNode = new ListNode(listNode[i]);
            temp->next = tempNode;
            temp = tempNode;
        }

        return result->next;
    }
    void list(ListNode* curNode, vector<int>& listNode){
        while(curNode != nullptr){
            listNode.push_back(curNode->val);
            curNode = curNode->next;
        }
    }
};



