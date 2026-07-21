/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (!head->next) return new Node(head->val);
        Node* temp = head;
        Node* newList;
        int itr = 0;
        Node* prev;
        vector<Node*>newListVector;
        map<Node*,int>randomIndices,actualIndices;
        while(temp){
            actualIndices[temp]=itr;
            temp = temp->next;
            itr++;
        }
        temp = head;
        while(temp){
            if(!temp->random){
                randomIndices[temp] = -1;
            }else{
                randomIndices[temp] = actualIndices[temp->random];
            }
            temp = temp->next;
        }
        itr = 0;
        temp = head;
        while(temp){
            Node* curr = new Node(temp->val);
            if(itr==0){
                newList = curr;
                prev = curr;
                itr++;
            }else{
                prev->next = curr;
                prev = prev->next;
            }
            newListVector.push_back(curr);
            temp = temp->next;
        }
        temp = head;
        int randIdx;
        for(int i=0;i<newListVector.size();i++){
            randIdx = randomIndices[temp];
            if(randIdx==-1)
                newListVector[i]->random = nullptr;
            else
                newListVector[i]->random = newListVector[randIdx];
            temp=temp->next;
        }
        return newList;
    }
};
