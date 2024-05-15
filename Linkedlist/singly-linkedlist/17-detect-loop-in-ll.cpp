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
        head= head->next;
    }

    head->next = newNode;
    return;
}

// using HashMap
bool detectLoopOrCycleHashMap(Node* head){
    unordered_set<Node* >s;
    while(head!=NULL){
        // if this node is already present
        // in hash map it means there is a cycle
        // because you wll be encountering the 
        // node for the second time
        if(s.find(head)!=s.end()){
            // the node is present
            return true;
        }

        // if we are seeing the node for 
        // the first time, insert it in a hash 
        s.insert(head);
        head = head->next;
    }

    return false;
   
}

// Detect loop in the linked list by modification in the node structure 
class Node2{
    public : 
    int data;
    Node2* next;
    bool visited;
    Node2(int value ){
        data = value;
        next = NULL;
        visited = false;
    }
};

bool detectLoopOrCycleModifyingNodeStructure(Node2* head2){
    Node2* temp2 = head2;
    while(temp2!=NULL){
        if(temp2->visited==false){
            temp2->visited = true;
        }else if(temp2->visited == true){
            return true;
        }
        temp2 = temp2->next;
    }
    return false;
}

void insertNode2(Node2* head2 , int value){
    Node2* newNode2 = new Node2(value);
    Node2* temp2 = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = newNode2;
    return;
}

bool detectLoopOrCycleFloydCycleAlgo(Node* head){
    Node* slowptr = head;
    Node* fastptr = head;

    while(slowptr && fastptr && fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr){
            return true;
        }
    }

    return false;
}


int main(){
    Node* head = new Node(12);
    insertNode(head, 13);
    insertNode(head , 14);
    insertNode(head,  17);
    insertNode(head, 19);
    insertNode(head, 23);

    if(detectLoopOrCycleHashMap(head)){
        cout<<"Loop found\n";
    }else{
        cout<<"\nNo loop found\n";
    }

    if(detectLoopOrCycleFloydCycleAlgo(head)){
        cout<<"Loop found\n";
    }else{
        cout<<"\nNo loop found\n";
    }


    head->next->next->next->next->next->next = head->next->next;

    if(detectLoopOrCycleHashMap(head)){
        cout<<"Loop found\n";
    }else{
        cout<<"\nNo loop found\n";
    }

    if(detectLoopOrCycleFloydCycleAlgo(head)){
        cout<<"Loop found\n";
    }else{
        cout<<"\nNo loop found\n";
    }

    Node2* head2 = new Node2(12);
    insertNode2(head2, 13);
    insertNode2(head2 , 14);
    insertNode2(head2,  17);
    insertNode2(head2, 19);
    insertNode2(head2, 23);

    if(detectLoopOrCycleModifyingNodeStructure(head2)){
        cout<<"Loop found\n";
    }else{
        cout<<"\nNo loop found\n";
    }

    head2->next->next->next->next->next->next = head2->next->next;


    if(detectLoopOrCycleModifyingNodeStructure(head2)){
        cout<<"Loop found\n";
    }else{
        cout<<"\nNo loop found\n";
    }


    return 0;
}