#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

void displayList(Node* head){
    Node* temp = head->next;
    if(head->next==NULL){
        cout<<head->data<<" ";
        return;
    }
    cout<<head->data<<" ";
    while(temp!=head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertNode(Node* head , int value){
    Node* newNode = new Node(value);
    while(head->next!=NULL){
        head = head->next;
    }

    head->next = newNode;
}

void splitCircularLLInto2Halves(Node* head){
    Node* slowPtr = head;
    Node* fastPtr = head;
    while(fastPtr->next!=head && fastPtr->next->next!=head){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // if there are even elements in the list
    // then move fastptr
    if(fastPtr->next->next==head){
        fastPtr = fastPtr->next;
    }

    // set the had pointer of the first half
    Node* head1 = head;

    // set the head pointer of the second half
    Node* head2 = NULL;
    if(head->next!=head){
        head2 = slowPtr->next;
    }

    // make the second half circular
    fastPtr->next = slowPtr->next;

    // make the first half circular
    slowPtr->next = head;

    cout<<"\nList 1 : ";
    displayList(head1);
    cout<<"\nList2 : ";
    displayList(head2);

}


int main(){
    Node* head = new Node(1);
    insertNode(head , 2);
    insertNode(head , 3);
    insertNode(head , 4);
    head->next->next->next->next = head;

    cout<<"Before splitting : ";
    displayList(head);
    cout<<"\n";

    splitCircularLLInto2Halves(head);

    return 0;
}