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

int countNodes(Node** head){
    if(*head==NULL){
        return 0;
    }else if((*head)->next ==NULL){
        return 1;
    }else{
        int counter=1;
        Node* temp = (*head)->next;
        while(temp!=(*head)){
            temp = temp->next;
            counter++;
        }
        return counter;
    }
}


int main(){
    Node* first = new Node(12);
    Node* second = new Node(13);
    Node* third = new Node(14);

    // linking 
    first->next = second;
    second->next = third;
    third->next = first;

    cout<<"Nodes count : "<<countNodes(&first)<<"\n";

    return 0;
}