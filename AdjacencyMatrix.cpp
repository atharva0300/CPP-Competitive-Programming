#include<bits/stdc++.h>
using namespace std;

void graph(){
     int n;
    cin>>n;
    int m;
    cin>>m;
    bool A[m][m];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        A[a][b] = true;        
    }
    int a,b;
    cin>>a>>b;
    if(A[a][b]){
        cout<<"There is an edge here\n";
    }else{
        cout<<"NO edge here\n";
    }
    cout<<"\n";
}


int main(){

    graph();
    return 0;
}