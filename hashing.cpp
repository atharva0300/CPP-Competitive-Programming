#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    unordered_map<int , string>temp;
    for(int i=0;i<n;i++){
        int a;
        string name;
        cin>>a>>name;
        temp[a] = name;
    }
    int s;
    cin>>s;
    for(int i=0;i<s;i++){
        int a;
        cin>>a;
        cout<<temp[a]<<"\n";
    }
    return 0;
    
}