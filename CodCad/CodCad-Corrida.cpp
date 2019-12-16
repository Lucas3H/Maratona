#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int carros, voltas;
	cin>>carros>>voltas;
	int a[carros][voltas];
	pair<int,int>tempo[carros];
		
	for(int i=0; i<carros; i++){
		tempo[i].first=0;
		tempo[i].second=i+1;
		for(int j=0; j<voltas; j++){
			cin>>a[i][j];
			tempo[i].first+=a[i][j];			
		}
	}
	
	sort(tempo, tempo+carros);
	
	cout<<tempo[0].second<<"\n"<<tempo[1].second<<"\n"<<tempo[2].second<<"\n";
	return 0;
}
