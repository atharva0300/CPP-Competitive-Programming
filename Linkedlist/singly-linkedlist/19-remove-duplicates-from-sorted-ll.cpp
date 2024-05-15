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

void insertNode(Node* head , int value){
    Node* newNode = new Node(value);
    while(head->next!=NULL){
        head=  head->next;
    }

    head->next = newNode;
    return;
}

Node* removeDuplicatesFromSortedLL(Node* head){
    set<int>s;
    Node* temp = head;
    while(temp!=NULL){
        s.insert(temp->data);
        temp = temp->next;
    }

    // obatin the set data and create a new ll
    Node* head2 = NULL;
    set<int>::iterator itr;
    for(itr=  s.begin(); itr!=s.end();itr++){
        if(head2==NULL){
            head2 = new Node(*itr);
        }else{
            insertNode(head2 , *itr);
        }
    }

    return head2;
}

void removeDuplicatesFromSortedLLNoSet(Node* head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, no duplicates to remove
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data == temp->next->data) {
            // Duplicate found, remove the next node
            Node* duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        } else {
            // Move to the next node
            temp = temp->next;
        }
    }
}

void displayList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

int main(){
    Node* head = new Node(11);
    insertNode(head , 11);
    insertNode(head , 11);
    insertNode(head , 21);
    insertNode(head ,43);
    insertNode(head , 43);
    insertNode(head , 60);

    cout<<"Before removing duplicates : ";
    displayList(head);
    Node* headReturn = removeDuplicatesFromSortedLL(head);
    cout<<"\nAfter remoiving diplicates : ";
    displayList(headReturn);
    cout<<"\n";

    Node* head2 = new Node(11);
    insertNode(head2 , 11);
    insertNode(head2 , 11);
    insertNode(head2 , 21);
    insertNode(head2 ,43);
    insertNode(head2 , 43);
    insertNode(head2 , 60);

    cout<<"Before removing duplicates : ";
    displayList(head2);
    cout<<"\n";
    removeDuplicatesFromSortedLLNoSet(head2);
    cout<<"\nAfter remoiving diplicates : ";
    displayList(head2);
    cout<<"\n";



    return 0;
}