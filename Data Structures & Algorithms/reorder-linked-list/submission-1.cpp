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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(temp){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head or !head->next){
            return;
        }
        ListNode* l1 = head;
        ListNode* middle = findMiddle(head);
        ListNode* temp = head;
        while(temp->next!=middle){
            temp = temp->next;
        }
        temp->next = nullptr;
        ListNode* l2 = reverseList(middle);
        ListNode* dummy = new ListNode(0);
        temp = dummy;

        int alt = 1;
        while(l1 and l2){
            if(alt){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
            alt = 1 - alt;
        }
        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }
        head = dummy->next;
        delete dummy;
    }
};
