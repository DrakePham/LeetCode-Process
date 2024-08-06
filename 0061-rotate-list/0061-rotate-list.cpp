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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        if (k==0) return head;
        ListNode* endList=head;
        int lengthList=1;
        while(endList->next!=nullptr){
            endList=endList->next;
            lengthList++;
        }
        endList->next=head;
        
        ListNode*cur = head;
        int newK=k % lengthList;
        int moveStep=lengthList-newK-1;
        while(moveStep--){
            cur=cur->next;
        }
        ListNode* result=cur->next;
        cur->next=nullptr;
        return result;
    }
};

// understand
// [] k=whatever; return []
// [1] k = whatever; return [1]
// [1,2] k =4 ; return [1,2]
// [1,2] k=3 return [2,1]
// k < 1, directly return original list

// time o(length of list X k) O(n)
// space O(1)

// match:
// multiple pass

// plan:

// ListNode cur, result,endList;

// while loop to calculate the length of the list

// if k > length of the list, if we rotate k=same length of the list, the list will be the same with the old one, so no matter that k, the rotation of the list will be the same with k mod the length of list, set newK equals to k mod the length of list

// we move the curr to newK-1, because the next node is what we need to return, for example
// [1,2,3,4,5] k =2, we need to return [4,5,1,2,3] so we need to move the result to 4 and cur to 3 which is 5-2-1=2
    
// we will move the endList to the final node of the list to connext the final node with the first node

// we use the cur node to set that node to nullptr, meaning that we break the cycle or break the pointer

// and we return the result node;




// implement draft;

// int newK = k%length of the list

// while (newK--!=0){
//  cur=cur.next;
// }
// result=cur.next;
// endList=cur.next;
// while(endList.next!=nullptr{
// endList=endList->next;
// }
// endList->next=head;
// cur.next=nullptr;

// return result;
      
// review:

      
      