#include<bits/stdc++.h>
using namespace std;


vector<int>arr[10];
bool visited[10];


void dfs(int s){
    // since we have now visited the node 
    // we will be making the visited property of the node as true 
    visited[s] = true;
    for(int i=0;i<arr[s].size();i++){
        if(visited[arr[s][i]]==false){
            dfs(arr[s][i]);
        }
    }
}

void initialize(){
    for(int i=0;i<10;i++){
        visited[i] = false;
    }
}


int main(){

    int nodes;
    int edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        // as the tree is unidirected 
        // we do the above
    }
    initialize();
    // initializing the visited property of all the nodes as false 
    
    int connectedComponents =0;

    for(int i=1;i<=nodes;i++){
        if(visited[i]==false){
            dfs(i);
            connectedComponents++;
        }
    }
    cout<<"Number of Connected Components : "<<connectedComponents;
    cout<<"\n";
    return 0;

}