/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node*temp = head;
        while(temp->next != nullptr){
            if(temp->data == key) return true;
            temp = temp->next;
        }
        if(temp->data== key) return true;
        return false;
    }
};
