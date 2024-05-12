#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertAtBeginning(Node** head , int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void traverseLinkedList(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void insertionAtEnd(Node** head , int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    
    if(head==nullptr){
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void insertionAtSpecificPosition(Node** head , int position , int data){
    //create a new node 
    Node* newNode = new Node();
    newNode->data = data;

    if(position==0 || (*head)==nullptr){
        newNode->next = (*head);

        (*head) = newNode;
        return;
    }

    // traverse the node before the specified position
    Node* current = *head;
    for(int i=0;i<position-1 && current->next!=nullptr;i++){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return;

}

int main(){
    Node* first = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    first->next = second;
    second->next = third;

    cout<<"Before insertion : \n";
    traverseLinkedList(first);
    insertAtBeginning(&first,  13);
    cout<<"\nAfter insertion ion the beginning : \n";
    traverseLinkedList(first);
    insertionAtEnd(&first , 14);
    cout<<"\nAfter insertion in the end : \n";
    traverseLinkedList(first);
    insertionAtSpecificPosition(&first , 2 , 15);
    cout<<"\nAfter insertion at specific position : \n";
    traverseLinkedList(first);

    delete first, second, third;
    return 0;
}