#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void traverseLinkedList(Node* head){
    if(head==nullptr){
        return;
    }
    while(head!=nullptr){
        cout<<head->data<<"\n";
        head=head->next;
    }
}

bool search(Node* head , int target){
    // check if the current node's data matches with the target value 
    while(head!=nullptr){
        if(head->data == target){
            return true;
            // value found
        }

        head = head->next;
    }
    return false;
}


bool search_recursive(Node* head , int target){
    if(head==nullptr){
        return false;
    }else if(head->data==target){
        return true;
    }else{
        return search_recursive(head->next , target);
    }
}


int main(){
    Node* head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    // linking the nodes 
    head->next = second;
    second->next = third;

    // traversing the linked list 
    traverseLinkedList(head);

    cout<<"value found? : "<<search(head , 2)<<"\n";
    cout<<"Value found> : "<<search(head , 12)<<"\n";
    cout<<"Value found? recursive : "<<search_recursive(head, 3)<<"\n";
    cout<<"Value found? recursive : "<<search_recursive(head , 12)<<"\n";

    delete head;
    delete second;
    delete third;


    return 0;
}