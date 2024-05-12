#include<bits/stdc++.h>
using namespace std;

// node structure 
struct Node{
    int data;
    Node* next;
};
// In this example, the Node struct contains an integer data field (data) to 
// store the information and a pointer to another Node (next) to establish the link to the next node in the list

void TraverseLinkedList(Node *head){
    Node *current = head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current =current->next;
    }
    cout<<"\n";
}


int main(){
    // create the nodes 
    Node* head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    // connect the nodes
    head->next = second;
    second->next = third;

    // traversal function
    TraverseLinkedList(head);

    delete head;
    delete second;
    delete third;

    return 0;
}