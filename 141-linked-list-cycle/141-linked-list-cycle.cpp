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
        ListNode* temp = head;
        set<ListNode*> unique;
        while(temp != NULL){
            if(unique.find(temp) != unique.end()){
                return true;
            }
            unique.insert(temp);
            temp = temp->next;   
        }
        
        return false;
    }
};