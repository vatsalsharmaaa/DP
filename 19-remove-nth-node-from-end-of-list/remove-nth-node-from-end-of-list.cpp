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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Dummy node before head to handle case of removing the first node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for(int i = 0; i <= n; i++){
            fast = fast->next;
        }

        // Move both pointers
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        // Now slow is before the node to delete
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;

        delete toDelete;  // free memory

        return dummy->next;
    }
};
