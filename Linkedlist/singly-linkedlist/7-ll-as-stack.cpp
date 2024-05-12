#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;
};

void push(Node** headRef , int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
    return;
}

void traverseLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

int main(){

    Node* head = NULL; 
    int x = 21;

    // use the push to insert the node in the front of hte linked list 
    push(&head , 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    cout<<"Linked list : ";
    traverseLinkedList(head);
    vector<int>v;
    Node *temp = head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp = temp->next;
    }
    vector<int>::iterator it;
    find(v.begin() , v.end() , x );
    if(it==v.end()){
        // the element is not found 
        cout<<"\nNO\n";
    }else{
        cout<<"\nYES\n";
    }


    return 0;
}