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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int, vector<int>, greater<int> > heap;
        int length=lists.size();
        for(int i = 0; i<length;i++){
            ListNode* temp=lists[i];
            while(temp!=nullptr){
                heap.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* result=dummy;
        while(!heap.empty()){
            ListNode* temp=new ListNode(heap.top());
            heap.pop();
            dummy->next=temp;
            dummy=temp;
        }
        return result->next;
    }
};
// use: priority heap or quick sort