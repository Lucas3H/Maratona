#include<iostream>

using namespace std;

int main(){
	int M, N;
	int m[1001], n[1001], r[1001];
	cin>>M>>N;
	
	for(int i=1; i<=M; i++){
		cin>>m[i];
	}
	
	for(int i=1; i<=N; i++){
		cin>>n[i];
	}
	
	for(int i=N; i>=1; i--){
		if(m[i]+n[i]<2){
			r[i]=m[i]+n[i];
		}
		else{
			r[i]=m[i]+n[i]-2;
			m[i-1]+=1;
		}
	}
	
	if(N==M){
		int x=N;
		for(int i=N; i>=1; i--){
			if(r[i]==0){
				x=i;
			}
			else{
				break;
			}
		}
		
		for(int j=1; j<=x-1; j++){
			cout<<r[j]<<" ";
		}
	}
	
	else if(N<M){
		for(int i=1; i<=N; i++){
			cout<<r[i]<<" ";
		}
		for(int i=N+1; i<=M;i++){
			cout<<m[i]<<" ";
		}
	}
	
	else{
		for(int i=1; i<=M; i++){
			cout<<r[i]<<" ";
		}
		for(int i=M+1; i<=N;i++){
			cout<<n[i]<<" ";
		}
	}
	
	return 0;
}
