#include<bits/stdc++.h>
using namespace std;


class Node{
    public : 
    int data;
    Node* next;
};

void push(Node** head,  int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    return;
}

void reverseLinkedList(Node** head){
    // initialie the current previous and next pointers 
    Node* current = (*head);
    Node* prev = NULL;
    Node* next = NULL;
    while(current!=NULL){
        // store hte next node 
        next = current->next;
        // reverse the current pointers direction
        current->next = prev;
        
        // movet he pointers one position ahead
        prev = current;
        current = next;
    }
    (*head) = prev;
    return;
}

void traverseLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void reverseLinkedListRecursive(Node* prev , Node* current, Node* next, Node** head){
    if(current==NULL){
        (*head) = prev;
        return;
    }else{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        reverseLinkedListRecursive(prev, current , next, head );
    }
}

void reverseLinkedListUsingStack(Node** head){
    Node* temp = (*head);
    stack<Node* >st;
    while(temp->next!=NULL){
        // till the last node
        // because, after this the reversing will begin
        st.push(temp);
        temp = temp->next;
    }
    (*head) = temp;

    while(!st.empty()){
        // while the stack is not empty
        temp->next = st.top();
        // obtain the top elemnent ( last elemetn )
        // asn  assign it ot the next of hte temp 
        st.pop();
        // remove the top elemnet of the stack
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}


int main(){
    Node* head = NULL;
    push(&head , 1);
    push(&head , 2);
    push(&head , 10);
    push(&head , 12);

    //reverse linked list 
    cout<<"Before reversing : ";
    traverseLinkedList(head);
    reverseLinkedList(&head);
    cout<<"\nAfter traversing : ";
    traverseLinkedList(head);
    cout<<"\nAfter reversing using recursiion : ";
    reverseLinkedListRecursive(NULL , head,  NULL , &head);
    traverseLinkedList(head);
    reverseLinkedListUsingStack(&head);
    cout<<"\nAfter reversing using Stack : ";
    traverseLinkedList(head);
    cout<<"\n";
    return 0;
}