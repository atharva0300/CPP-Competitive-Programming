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

void exchangeFirstAndLastNodes(Node** head){
    if(*head==NULL){
        return;
    }else if((*head)->next == NULL){
        return;
    }else{
        Node* temp = (*head)->next;
        while(temp->next!=(*head)){
            temp = temp->next;
        }

        int temp2 = (*head)->data;
        (*head)->data = temp->data;
        temp->data = temp2;
        return;
    }
}

void displayList(Node* head){
    if(head==NULL){
        return;
    }else if((head)->next==NULL){
        cout<<(head)->data<<"\n";
        return;
    }else{
        cout<<(head)->data<<" ";
        Node* temp = (head)->next;
        while(temp!=(head)){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    return;
}

int main(){
    Node* first = new Node(12);
    Node* second = new Node(13);
    Node* third = new Node(14);

    // linking 
    first->next = second;
    second->next = third;
    third->next = first;

    cout<<"Before swapping : ";
    displayList(first);
    cout<<"\nAfter swapping : ";
    exchangeFirstAndLastNodes(&first);
    displayList(first);

    return 0;
}