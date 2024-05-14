#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deletionAtBeginning(Node** head){
    Node* temp = (*head)->next;
    (*head)->next = nullptr;
    (*head) = temp;
    return;
}

void traverseLinkedList(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

void deletionInEnd(Node** head){
    if(*head==nullptr){
        return;
    }
    Node* temp = *head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    temp->next = nullptr;
    return;
}

void deletionAtSpecificPosition(Node** head , int position){
    if(position==0 || *head==nullptr){
        head = nullptr;
        return;
    }

    Node* temp = *head;
    for(int i=0;i<position-1 && temp->next!=nullptr;i++ ){
        temp = temp->next;
    }
    Node* temp2 = temp->next->next;
    temp->next->next = nullptr;
    temp->next = temp2;
    return;
}

void deletionAtSpecificPositionRecursive(Node* temp , int counter, int position){
    if(position==0 || temp==nullptr){
        temp = nullptr;
        return;
    }else if(counter<position-1 && temp->next!=nullptr){
        temp = temp->next;
        counter++;
        return deletionAtSpecificPositionRecursive(temp , counter , position);
    }else{
        Node* temp2 = temp->next->next;
        temp->next->next = nullptr;
        temp->next = temp2;
        return;
    }
}

void deletionOfGivenKey(Node** head , int key){
    Node* temp = (*head);
    Node* prev = NULL;

    if(prev==NULL && temp->data==key){
        prev = temp;
        temp = temp->next;
        prev->next = NULL;
        (*head) = temp;
        return;
    }

    while(temp->data!=key){
        prev = temp;
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = nullptr;
    prev->next = temp2;
    return;
}

void deletionOfGivenKeyRecursive(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // Base case: If key is not found
    if (temp == NULL) return;

    // If key is found at first position
    if (temp->data == key) {
        *head = temp->next;
        delete temp;
        deletionOfGivenKeyRecursive(head, key); // Check for more occurrences of key
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    delete temp;

    // Recursive call to check for more occurrences of key
    deletionOfGivenKeyRecursive(head, key);
}


int main(){
    Node* first = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};
    Node* fourth = new Node{4};
    Node* fifth = new Node{5};
    Node* sixth = new Node{6};
    Node* seventh = new Node{7};
    Node*eight = new Node{8};

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;

    cout<<"Before deletion : ";
    traverseLinkedList(first);
    deletionAtBeginning(&first);
    cout<<"\nAfter deletion from the beginning : ";
    traverseLinkedList(first);
    deletionInEnd(&first);
    cout<<"\nAfter deletion at the end : ";
    traverseLinkedList(first);
    deletionAtSpecificPosition(&first, 2);
    cout<<"\nAfter deletion at specific position : ";
    traverseLinkedList(first);
    Node* temp = first;
    deletionAtSpecificPositionRecursive(temp , 0, 2);
    cout<<"\nAfter recursive deletion : ";
    traverseLinkedList(first);
    deletionOfGivenKey(&first , 2);
    cout<<"\nAfter deletion of given key ( iterative ) : ";
    traverseLinkedList(first);
    deletionOfGivenKeyRecursive(&first , 6);
    cout<<"\nAfter deletion of given key ( recursive ): ";
    traverseLinkedList(first);
    

    delete first, second, third, fourth, fifth, sixth, seventh;
    return 0;
}