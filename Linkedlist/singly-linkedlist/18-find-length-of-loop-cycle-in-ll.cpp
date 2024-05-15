#include<bits/stdc++.h>
using namespace std;


class Node{
    public : 
    int data;
    Node* next;
    int length;
    bool visited;
    Node(int value){
        data =value;
        next = NULL;
        length =0;
        visited = false;
    }
};

void insertNode(Node* head , int value){
    Node* newNode = new Node(value);
    while(head->next!=NULL){
        head = head->next;
    }

    head->next = newNode;
    return;
}

int findLengthOfLoop(Node* head){
    Node* temp = head;
    int counter=0;
    while(temp->next->visited==false){
        counter++;
        temp->visited = true;
        temp->length = counter;
        temp = temp->next;
    }

    // temp->visited = true here
    // obtain the difference
    temp->length = ++counter;
    int difference = temp->length - temp->next->length;
    return difference+1;
}
int main(){
    Node* head = new Node(1);
    insertNode(head , 2);
    insertNode(head , 3);
    insertNode(head ,4);
    insertNode(head , 5);
    
    // linking to form a loop
    head->next->next->next->next->next = head->next;

    cout<<"Length of the cycle : "<<findLengthOfLoop(head)<<"\n";

    return 0;
}