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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) return nullptr;
        if (head->next==nullptr) return head;
        
        
        unordered_map<int, int> map;
        ListNode* temp = head;
        
        while(temp!=nullptr){
            map[temp->val]++;
            temp=temp->next;
        }
        vector<int> res;
        while(head!=nullptr){
            if(map.at(head->val)==1){
                res.push_back(head->val);
            }
            head=head->next;
        }
        ListNode* tempNode = new ListNode(0);
        ListNode* dummy=tempNode;
        // ListNode* result=tempNode->next;
        for(int i =0;i<res.size();i++){
            ListNode* add= new ListNode(res[i]);
            // cout<<res[i]<<"--";
            tempNode->next=add;
            tempNode=add;
        }

        
        return dummy->next;
        
        
        
    }
};

// Understand:
// [1,3,3,5,6,7,8,8] return [1,5,6,7]
// [] return []
// [1] return [1]
// [1,1] return []
// [1,2,2] return [1]

// time: n
// space: 1

// Match:
// Use hashtable

// Plan:
// have 1 temp node = head
// we add each value to hashtable
// use temp to loop again the list, if that value in hash = 1, add that node to the result list

// Review:



