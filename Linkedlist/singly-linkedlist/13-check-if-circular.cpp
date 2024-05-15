#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;
    Node(int data){
        data = data;
        next = NULL;
    }
};


bool checkCircular(Node** head){
    // if linked list is empty 
    if(*head==NULL){
        return true;
    }
    Node* temp = (*head)->next;
    while(temp!=NULL && temp!=(*head)){
        temp = temp->next;
    }
    return (temp==*head);
}


int main(){
    Node* first = new Node(12);
    Node* second = new Node(13);
    Node* third = new Node(14);

    // linking 
    first->next = second;
    second->next = third;
    third->next = first;

    cout<<"is circular? : "<<checkCircular(&first)<<"\n";

    Node* fourth = new Node(16);
    Node* fifth = new Node(19);
    Node* sixth = new Node(20);

    // linking 
    fourth->next = fifth;
    fifth->next = sixth;

    cout<<"is circular? : "<<checkCircular(&fourth)<<"\n";

    third->next = NULL;
    cout<<"is circular? : "<<checkCircular(&first)<<"\n";
    
    return 0;
}