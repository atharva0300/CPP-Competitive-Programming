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

void insert(Node* head , int value){
    Node* newNode = new Node(value);
    while(head->next!=NULL){
        head = head->next;
    }

    head->next = newNode;
    return;
}

void printReverseLinkedListRecursive(Node* head){
    if(head==NULL){
        return;
    }
    printReverseLinkedListRecursive(head->next);

    cout<<head->data<<" ";
}

void printReverseLinkedList(Node* head){
    vector<int>temp;
    while(head!=NULL){
        temp.push_back(head->data);
        head = head->next;
    }
    reverse(temp.begin() , temp.end());
    for(auto it : temp){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main(){
    Node* first = new Node(13);
    insert(first , 14);
    insert(first , 15);
    insert(first , 16);
    
    cout<<"Printing reverse of linekd list : ";
    printReverseLinkedList(first);
    cout<<"\n";
    cout<<"Printing reverse of linked list using recursion : ";
    printReverseLinkedListRecursive(first);
    cout<<"\n";

    return 0;
}