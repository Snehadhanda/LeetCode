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
//METHOD 1: USING MAP
//THIS APPROCH IS OK BUT THE INTERVIEWER DOES NOT WANT EXTRA SPACE TO STORE THE KEY VALUE PAIRS AND ALSO WE KNOW THAT USING MAP IS NOT A GOOD PRACTISE
//for this first we will create all the dummy nodes and store them
//then we will connect the nodes of dummy list according to the original nodes
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(head == nullptr) return  nullptr;
//         Node*temp = head;
//         map<Node*,Node*>mp;
//         while(temp != nullptr){
//             Node* newNode = new Node(temp->val); //newnode me temp ki value copy kr rha hai
//             mp[temp] = newNode;   // storing the original node and the copied node in the map....here original node will work as a key and copied node will be value;
//             temp =temp->next;
//         }
//         //now we will again reset the temp to head.....so that we can connect the copied newNode according to the original nodes
//             temp = head;
//         Node*copyNode = mp[temp];
//         while(temp != nullptr){
//             copyNode = mp[temp];
//             copyNode->next  = mp[temp->next]; 
//             copyNode->random = mp[temp->random];
//             temp = temp->next;
//         }
//         return mp[head];
//     }
// };


//2nd METHOD:
//we will insert the copied nodes after creating inbetween the original node;
//resert the temp = head;
//now we will link the random of the copied nodes;
//connect the next pointers
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node*temp = head;
        while(temp != nullptr){
            Node*copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
        temp = head;
        //connect the random pointers
        while(temp != nullptr){
            if(temp->random != nullptr){
                temp->next-> random = temp->random->next;
            }
            temp = temp->next->next;
        }
            //now we will connect the next of the copied nodes and for that we will will create a dummy node
            Node* dNode = new Node(-1);
            Node* copyList = dNode;
            temp = head;
            while(temp!=nullptr){
                Node*copyNode = temp->next;  // Extract the copied node
                temp->next = copyNode->next;  // Restore the original list
                
                copyList->next = copyNode;  // Append to the copied list
                copyList = copyList->next;  // Move to the next in the copied list
                
                temp = temp->next;   // Move to the next original node
            }
        return dNode->next;   // Return the head of the copied list
    }
};