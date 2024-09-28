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

//for this first we will create all the dummy nodes and store them
//then we will connect the nodes of dummy list according to the original nodes
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return  nullptr;
        Node*temp = head;
        map<Node*,Node*>mp;
        while(temp != nullptr){
            Node* newNode = new Node(temp->val); //newnode me temp ki value copy kr rha hai
            mp[temp] = newNode;   // storing the original node and the copied node in the map....here original node will work as a key and copied node will be value;
            temp =temp->next;
        }
        //now we will again reset the temp to head.....so that we can connect the copied newNode according to the original nodes
            temp = head;
        Node*copyNode = mp[temp];
        while(temp != nullptr){
            copyNode = mp[temp];
            copyNode->next  = mp[temp->next]; 
            copyNode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};