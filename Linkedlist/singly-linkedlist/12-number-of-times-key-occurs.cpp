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

void findNumberOfTimesKeyOccures(Node* head , int key){
    int counter=0;
    while(head!=NULL){
        if(head->data==key){
            counter++;
        }
        head = head->next;
    }
    cout<<"The key "<<key<<" occures "<<counter<<" times\n";
    return;
}

void findNumberOfTimesKeyOccuresRecursive(Node* head , int key , int counter){
    if(head==NULL){
        cout<<"The key "<<key<<" occures "<<counter<<" times ( Recursive )\n";
        return;
    }else if(head->data==key){
        return findNumberOfTimesKeyOccuresRecursive(head->next , key , ++counter);
    }else{
        return findNumberOfTimesKeyOccuresRecursive(head->next , key , counter);
    }
}




int main(){
    Node* head = NULL;
    push(&head , 12);
    push(&head , 13);
    push(&head , 10);
    push(&head , 13);
    push(&head , 3);
    push(&head , 13);
    push(&head , 3);

    traverseList(head);
    findNumberOfTimesKeyOccures(head , 13);
    findNumberOfTimesKeyOccuresRecursive(head , 13 , 0);

    return 0;
}