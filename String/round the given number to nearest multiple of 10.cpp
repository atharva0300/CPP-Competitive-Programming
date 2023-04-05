#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"\nEnter a number : ";
	cin>>n;
	int number = 10;
	while(1){
		int r = n%number;
		if(r/10==0){
			if(r<5){
				cout<<n-r;
			}else{
				cout<<n-r+10;
			}
			break;
		}
		number = number+10;
	}
	
	
	cout<<"\n";
	system("pause");
	return 0;
}