#include<bits/stdc++.h>
using namespace std;

int main(){

    int nodes;
    int edges;
    cin>>nodes>>edges;
    vector<int>adj[10];
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=0;i<=nodes;i++){
        cout<<"\nAdjacency List of node : "<<i<<" : ";
        for(int j=0;j<adj[i].size();j++){
            if(j==adj[i].size()-1){
                cout<<adj[i][j];
            }else{
                cout<<adj[i][j]<<" --> ";
            }
        }
    }
    cout<<"\n";

    return 0;
}