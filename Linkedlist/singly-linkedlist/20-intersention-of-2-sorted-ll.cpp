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

void displayList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void insertNode(Node* head , int value){
    Node* newNode = new Node(value);
    while(head->next!=NULL){
        head = head->next;
    }

    head->next = newNode;
}

void intersectionOf2SortedLLUsingVector(Node* head1 , Node* head2){
    vector<int>v;
    while(head1!=NULL){
        v.push_back(head1->data);
        head1 = head1->next;
    }

    Node* head3 = NULL;
    while(head2!=NULL){
        if(find(v.begin() , v.end() , head2->data)!=v.end()){
            // found the element
            if(head3==NULL){
                head3 = new Node(head2->data);
            }else{
                insertNode(head3 , head2->data);
            }
        }
        head2 = head2->next;
    }
    cout<<"Intersection of the 2 lists : ";
    displayList(head3);
    cout<<"\n";
}

void intersectionOf2LL(Node* head1 , Node* head2){
    Node* head3 = NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data){
            if(head3==NULL){
                head3 = new Node(head1->data);
            }else{
                insertNode(head3 , head1->data);
            }
            head1 = head1->next;
        }else if(head1->data > head2->data){
            head2 = head2->next;
        }else if(head1->data < head2->data){
            head1 = head1->next;
        }
    }

    cout<<"Intersection of 2 lists : ";
    displayList(head3);
    cout<<"\n";
}

Node* intersectionOf2ListsRecursive(Node* head1 , Node* head2){
    if(head1==NULL || head2==NULL){
        // if either head1 or head2 reaches NULL
        return NULL;
    }

    if(head1->data < head2->data){
        return intersectionOf2ListsRecursive(head1->next , head2);
    }else if(head1->data > head2->data){
        return intersectionOf2ListsRecursive(head1 , head2->next);
    }

    // if head1->data == head2->data
    Node* head3 = new Node(head1->data);
    head3->next = intersectionOf2ListsRecursive(head1->next , head2->next);
    return head3;
}


int main(){
    Node* head1 = new Node(1);
    insertNode(head1 , 2);
    insertNode(head1 , 3);
    insertNode(head1 , 4);
    insertNode(head1 , 6);

    cout<<"List 1 : ";
    displayList(head1);

    Node* head2 = new Node(2);
    insertNode(head2 , 4);
    insertNode(head2 , 6);
    insertNode(head2 , 8);

    cout<<"\nList 2 : ";
    displayList(head2);
    cout<<"\n";

    intersectionOf2SortedLLUsingVector(head1 , head2);
    intersectionOf2LL(head1 , head2);
    Node* headResult = intersectionOf2ListsRecursive(head1 , head2);
    cout<<"Intersection of the 2 lists ( Recursive ) : ";
    displayList(headResult);
    

    return 0;
}