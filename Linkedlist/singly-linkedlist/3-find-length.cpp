#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int findLength(Node* head){
    int counter=0;
    while(head!=nullptr){
        counter++;
        head = head->next;
    }

    return counter;
}

int findLengthRecursize(Node* head , int counter){
    if(head==NULL){
        return counter;
    }else{
        counter++;
        return findLengthRecursize(head->next , counter);
    }
}

int main(){
    Node* first = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    first->next = second;
    second->next = third;

    cout<<"Length : "<<findLength(first)<<"\n";
    cout<<"\nLength Recursize : "<<findLengthRecursize(first , 0)<<"\n";


    return 0;
}