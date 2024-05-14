#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;
};

void traverseList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}


void push(Node** head , int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    return; 
}

int getLength(Node* head){
    int counter=0;
    while(head!=NULL){
        counter++;
        head = head->next;
    }
    return counter;
}

void getNthNodeFromEnd(Node* head , int length , int n){
    int index = length - n;
    int counter=0;
    while(head!=NULL && counter!=index){
        head = head->next;
        counter++;
    }

    if(head==NULL){
        cout<<"\nN is greater than the length of the linked list\n";
    }else{
        cout<<"\nThe "<<counter<<"th node from the end is : "<<head->data<<"\n";
    }

    return;
}

void getNthNodeFromEndTwoPointer(Node* head , int n){
    Node* main_ptr = head;
    Node* ref_ptr = head;
    // create a distance of n in between the main_ptr and the ref_ptr
    int counter=1;
    while(counter!=n){
        ref_ptr = ref_ptr->next;
        counter++;
    }
    
    // increment the ref_ptr and the main_ptr by one step
    // till the ref_ptr does not reach the last node 
    while(ref_ptr->next!=NULL){
        ref_ptr = ref_ptr->next;
        main_ptr = main_ptr->next;
    }

    // now the main_ptr points to the nth node from the end
    cout<<"\nThe "<<n<<"th node from the end is ( 2 pointers ): "<<main_ptr->data<<"\n";
    return;

}


int main(){
    Node* head = NULL;
    push(&head , 12);
    push(&head , 13);
    push(&head , 10);
    push(&head , 15);

    cout<<"Length of the list : "<<getLength(head)<<"\n";
    int length = getLength(head);
    traverseList(head);
    getNthNodeFromEnd(head , length, 3);
    getNthNodeFromEndTwoPointer(head , 3);

    return 0;
}