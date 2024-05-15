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
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void insertNode(Node* head , int value){
    Node* newNode = new Node(value);
    while(head->next!=NULL){
        head = head->next;
    }

    head->next = newNode;
}

int main(){

    return 0;
}