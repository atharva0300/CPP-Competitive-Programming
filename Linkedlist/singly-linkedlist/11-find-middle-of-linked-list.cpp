#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;
};

void push(Node** head , int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    return;
}

void traverseList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
    return;
}

int findMiddle(Node* head){
    int counter=0;
    while(head!=NULL){
        counter++;
        head = head->next;
    }
    int middle = 0;
    if(counter%2==0){
        // of the legnth is even
        middle = counter/2;
    }else{
        // for odd length
        middle = floor(counter/2);
    }
    return middle;
}

void findMiddleOfLinkedList(Node* head){
    int middle = findMiddle(head);
    int counter=0;
    while(counter!=middle){
        head = head->next;
        counter++;
    }
    cout<<"Middle elemnet : "<<head->data<<"\n";
    return;
}

// using Floyd's cycle finding algorithm
void findMiddleOfLinkedListUsingFloydCycleAlgo(Node *head){
    /* 
    We can use the Floyd’s Cycle Finding Algorithm, also known as Hare and Tortoise Algorithm to find the middle of the linked list. 
    Traverse linked list using a slow pointer and a fast pointer. 
    Move the slow pointer to the next node(one node forward) and the fast pointer to the next of the next node(two nodes forward). 
    When the fast pointer reaches the last node or NULL, then the slow pointer will reach the middle of the linked list.

    In case of odd number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will reach the last node 
    and in case of even number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will become NULL.
    */

   Node* fast_ptr = head;
   Node* slow_ptr = head;
   while(fast_ptr!=NULL && fast_ptr->next!=NULL){
    fast_ptr = fast_ptr->next->next;
    slow_ptr = slow_ptr->next;
   }

   // the slow ptr is the middle node
   cout<<"Middle node using Floyd cycle algo : "<<slow_ptr->data<<"\n";
   return;
}


int main(){
    Node* head = NULL;
    push(&head , 12);
    push(&head , 13);
    push(&head , 10);
    push(&head , 3);

    traverseList(head);
    findMiddleOfLinkedList(head);
    findMiddleOfLinkedListUsingFloydCycleAlgo(head);
    

    return 0;
}