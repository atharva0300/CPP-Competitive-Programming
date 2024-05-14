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

void getNthNode(Node* head , int n){
    int counter=0;
    while(head!=NULL && counter!=n){
        head = head->next;
        counter++;
    }
    if(head==NULL){
        cout<<"\nn is greater than the size of Linked list";
    }else{
        cout<<"\nThe node at index "<<counter<<" is "<<head->data<<"\n";
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

void getNthNodeRecursive(Node* head , int n , int counter){
    if(counter==n){
        cout<<"The node at index "<<counter<<" is found ( recursive ) : "<<head->data<<"\n";
        return;
    }else if(head==NULL){
        cout<<"\nN is greater than the size of array\n";
        return;
    }else{
        return getNthNodeRecursive(head->next , n , ++counter);
    }
}

int main(){
    Node* head = NULL;
    push(&head , 12);
    push(&head , 13);
    push(&head , 10);
    push(&head , 15);

    getNthNode(head , 2);
    getNthNodeRecursive(head , 3 , 0);
    traverseList(head);

    return 0;
}