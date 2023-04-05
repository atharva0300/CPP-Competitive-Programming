#include<bits/stdc++.h>
using namespace std;

#define size 7
// defining the size of the hash table 
struct node{
    int data;
    struct node* next;
};

struct node* chain[size];
// creating a global array ( the hash table  )
// creating an array of chain of the size as size 

void init(){
    int i;
    for(int i=0;i<size;i++){
        chain[i] = NULL;
    }
    // first initializing all the values of the hash table 
    // as NULL ( before filling )
}

void insert(int value){
    // code to insert the value goes here
    // create a newnode with the value 

    struct node *newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    // the next pointer of an individual node is null 
    // we will be creating the chain of the node soon 

    // calculate the hash ket 
    int key = value %size ;

    // check if chain[key] is empty or not
    if(chain[key]==NULL){
        chain[key] = newNode;
        // if there is no node present at that index 
        // then we insert the new node whih we have created
    }else{
        // condition for collision
        // add the node at the end of the chain[key]

        struct node *temp = chain[key];
        while(temp->next){
            // till the end of the linked list 
            temp  = temp->next;
            // keep looking forward
        }

        // when temp reaches the last node of the linked list 
        temp->next = newNode;
        // insert the new node after that node
    }
}

// printing the hash table
void print(){
    int i;
    for(int i=0;i<size;i++){
        struct node *temp = chain[i];
        // initialize a temp node to the node that is 
        // present at the current index in the hash table
        cout<<"chain["<<i<<"] --> ";
        
        // iterating over the linked list atteched to the current node 
        while(temp){
            // till the last node 
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
}


int main(){

    // initialzing an array of list to NULL 
    init();

    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    print();
    // printing the entire hash table

    return 0;
}