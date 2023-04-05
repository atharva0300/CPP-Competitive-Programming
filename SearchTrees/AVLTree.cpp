#include<bits/stdc++.h>
using namespace std;

// an avl tree node 
class node{
    public : 
    int key;
    node *left;
    node *right;
    int height;
};

// a function to get the maximum 
// of the 2 integers 
int max(int a , int b);

// a function to get the height of the tree
int height(node *temp){
    if(temp==NULL){
        return 0;
    }

    return temp->height;
}

// a function to get maximum 
// of the 2 integers
int max(int a , int b){
    return (a>b)? a : b;
}

// helper function that allocates 
// new node with the given key and 
// NULL left and right pointers 
node *newNode(int key){
    node *temp = new node();
    // creating a new temp node 
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    // setting the left and the right pointers as NULL 
    // new node is initially added at the leaf 

    return temp;
}


// a function to get right rotate 
// subtree roote with y 
node *rightRotate(node *y){
    node *x = y->left;
    node *t2 = x->right;

    // perform rotation 
    x->right = y;
    y->left = t2;

    // update heights 
    y->height = max(height(y->left) , height(y->right)) + 1;
    x->height = max(height(x->left) , height(x->right)) + 1;

    // retrun new node 
    return x;
}


// a function to left 
// rotate subtree rooted with x
node *leftRotate(node *x){
    node *y = x->right;
    node *t2 = y->left;

    // perform rotation 
    y->left = x;
    x->right = t2;

    // update heights
    x->height = max(height(x->left) , height(x->right)) + 1;
    y->height = max(height(y->left) , height(y->right)) + 1;


    // return new root 
    return y;
}


// get balance factor of node N 
int getBalance(node *n){
    if(n==NULL){
        return 0;
    }

    return height(n->left) - height(n->right);
}

node *insert(node *node , int key){
    // 1. perform the normal BST insertion 
    if(node==NULL){
        return(newNode(key));
    }

    if(key < node->key){
        node->left = insert(node->left , key);
    }else if(key > node->key){
        node->right = insert(node->right , key);
    }else{
        return node;
    }

    // update the height of this ancestor node 
    node->height = 1 + max(height(node->left) , height(node->right));

    // get the balance factor of this ancestor 
    // node to check whether this node became
    // unbalanced
    int balance = getBalance(node);

    // if this node becomes unbalanced, then 
    // there are 4 cases

    // left left case 
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }

    // right right case
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }

    // left right case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right left case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer 
    return node;
}

// a function to print preorder 
// traversal of the tree
 // the function also prints height 
 // of every node
 void preorder(node *root){
     if(root!=NULL){
         cout<<root->key<<" ";
         preorder(root->left);
         preorder(root->right);
     }
 }


int main(){

    // creating the root node 
    // of the avl tree 
    node *root = NULL;

     /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
     
    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */

   cout<<"Preorder traversal of the constructed AVL tree is : ";
   preorder(root);

   cout<<"\n";

    return 0;
}