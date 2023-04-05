#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node *left , *right;
    // left and the right pointers for the left and the right child
};

node *newNode(int data){
    // creating a new node 
    node *temp = new node;
    //no constructor invooked 
    // so, no value passed to the node ( );

    temp->key = data;
    temp->left = NULL;
    temp->right =NULL;
    // making the left and the right child ofthe node 
    // as NULL while inserting 

    // returning the newly created node temp 
    return temp;
}

void inorder(struct node *root){
    // inorder traversal 
    // => IVR 
    // LEFT , VISIT , RIGHT 
    if(root==NULL){
        return;
    }

    inorder(root->left);

    cout<<root->key<<" ";

    inorder(root->right);
}

void deleteDeepest(node *root , node *d_key){
    // the d_key is the node that is to be deleated 
    
    // creating a queue to keep track of all the nodes 
    // while traversing 
    queue<node*>q;
    q.push(root);

    node *temp;
    while(!q.empty()){
        // getting the front node from queue 
        temp = q.front();
        q.pop();

        if(temp==d_key){
            // make the currect node as null 
            temp = NULL;
            // and delete the struct 
            // because, the struct will be hanging in the memory 
            delete (temp);
            return;
        }

        if(temp->left){
            if(temp->left==d_key){
                // make the temp node's left as NULL 
                // to disconnect that node 
                temp->left = NULL;
                delete ( temp->left);
                return ;
            }else{
                // else if the d_key is not found, then we push that node in the queue 
                q.push(temp->left);
            }
        }

        if(temp->right){
            if(temp->right==d_key){
                // make the temp node's right as NULL 
                // to disconnect that node 
                temp->right = NULL;
                delete (temp->right);
                return;
            }else{
                q.push(temp->right);
                // else if the d_key is not found, then we push that node in the queue
            }
        }
    }


}


node *deletion(node *root , int key ){
    if(root==NULL){
        return NULL;
    }

    if(root->left==NULL && root->right==NULL){
        if(root->key == key){
            return NULL;
            // deletaing the node, will return null
        }else{
            return root;
            // since, the key is not found in the node, the current node won't get deleated
        }
    }

    // creating a queue to keep track of all the nodes that we are visiting 
    queue<node*> q;
    q.push(root);
    // pushing the root node in the queu 
    
    node *temp;
    //creating a temp node
    // to keep tract of the top node in the queue
    node *key_node= NULL;
    // null struct

    // we traverse the tree, using such a method 
    // that after traversing all the nodes
    // we finally get the bottom most - right most node of the tree
    while(!q.empty()){
        temp = q.front();
        q.pop();


        if(temp->key==key){
            // if the key is found, then we coyp that node in the key_node struct 
            key_node = temp;
        }if(temp->left){
            q.push(temp->left);
            // if the key is not found, then we find it in the left child of the current node
        }if(temp->right){
            q.push(temp->right);
                // if the key is not found, then we fund it in the right child of the current node
            
        }
    }

    // when we have found the node with the right key 
    if(key_node!=NULL){
        int x = temp->key;
        // store the key 
        deleteDeepest(root , temp);
        // the temp here is the bottom most and the right most node of the tree
        // after deleation of that node 
        // we change the value of the key_node
        key_node->key = x;
    }

    return root;
    // return the root that it will be used to traverse the tree again 
}



int main(){

    // creating the root node
    struct node *root = newNode(12);
    root->left = newNode(13);
    root->right = newNode(10);
    root->left->left = newNode(9);
    root->right->right = newNode(14);

    // dispalying the tree
    cout<<"\nInorder traversal : "; 
    inorder(root);

    cout<<"\n";

    int key = 10;
    // deleating the key 10 
    root = deletion(root , key );

    // displaying  teh tree after deleation 
    cout<<"\nAfter deletion  :";
    inorder(root);

    cout<<"\n";
    return 0;
}