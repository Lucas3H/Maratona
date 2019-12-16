#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n, dep;
	cin>>n>>dep;
	
	pair<int,int>v[n];
	for(int i=0; i<n; i++){
		cin>>v[i].second;
		v[i].first=v[i].second%dep;
	}
	
	sort(v, v+n);
	
	/*
	int indice=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[j]%dep==a[i] && v[j]!=-1){
				v_certo[indice]=v[j];
				v[j]=-1;;
				indice++;
				break;
			}
		}
	}*/
	
	//Desempate
	for(int i=0; i<n-1; i++){
		if(v[i].first==v[i+1].first && v[i].second>v[i+1].second){
			int temp=v[i].second;
			v[i].second=v[i+1].second;
			v[i+1].second=temp;
		}
	}
	
	for(int i=n-1; i>=0; i--){
		cout<<v[i].second<<" ";
	}
	
	
}
