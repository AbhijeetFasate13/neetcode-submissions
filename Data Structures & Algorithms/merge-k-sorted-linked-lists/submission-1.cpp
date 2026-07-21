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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(list1 && list2){
            if(list1->val<list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1){
            temp->next = list1;
        }
        if(list2){
            temp->next = list2;
        }
        temp = dummy->next;
        delete dummy;
        return temp;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        queue<ListNode*>q;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
            q.push(lists[i]);
        }
        while(q.size()>1){
            int sz = q.size();
            for(int i=0;i<sz/2;i++){
                ListNode* a = q.front();
                q.pop();
                ListNode* b = q.front();
                q.pop();
                q.push(mergeTwoLists(a,b));
            }
            if(sz&1){
                q.push(q.front());
                q.pop();
            }
        }
        return q.front();
    }
};
