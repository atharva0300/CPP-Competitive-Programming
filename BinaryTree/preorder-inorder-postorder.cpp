#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
    // keeping track of the right and the left nodes 
};


// declaring the constructor of the structure 
node *newNode(int data){
    // creating a new node 
    node *temp = new node;
    // name of the new node => temp 
    // constructor invoked
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    // making teh left and the right poiinters as NULL
}

void inorder(struct node *temp){
    if(temp==NULL){
        return;
    }
    // if the temp node is NULL, then return 

    // inorder => LVR 
    // left , visited and right
    inorder(temp->left);

    cout<<temp->data<<" ";

    inorder(temp->right);
}

void preorder(struct node *temp){
    if(temp==NULL){
        return;
    }

    // if the temp node is NULL,  then return 

    // preorder => VLR 
    // visit , left , and right

    cout<<temp->data<<" ";

    preorder(temp->left);

    preorder(temp->right);
}

void postorder(struct node *temp){
    if(temp==NULL){
        return;
    }

    // if the temp node is NULL, then return 

    // postorder=> LRV 
    // left , right , and visited

    postorder(temp->left);

    postorder(temp->right);

    cout<<temp->data<<" ";
}




int main(){
    node *root  = newNode(1);

    // creating                the root node 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);


    cout<<"\nPreorder traversal : ";
    preorder(root);

    cout<<"\nInorder traversal : ";
    inorder(root);

    cout<<"\nPostorder traversal : ";
    postorder(root);

    cout<<"\n";

    return 0;
}