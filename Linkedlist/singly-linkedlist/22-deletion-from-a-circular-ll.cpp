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
        // only one node 
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

void deleteNode(Node* head , int target){
    Node* temp = head->next;
    if(head->data==target){
        head = NULL;
        return;
    }
    if(head->next->data == target){
        head->next = NULL;
        return;
    }

    while(temp!=head){
        if(temp->next->data == target){
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            temp2->next = NULL;
            free(temp2);
        }
        temp = temp->next;
    }

}


int main(){
    Node* head = new Node(2);
    insertNode(head , 5);
    insertNode(head , 7);
    insertNode(head , 8);
    insertNode(head , 10);

    head->next->next->next->next->next = head;

    cout<<"Before deletion : ";
    displayList(head);
    deleteNode(head , 5);
    cout<<"\nAfter deletion : ";
    displayList(head);
    

    return 0;
}