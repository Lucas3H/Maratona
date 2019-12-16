#include<iostream>
#include<cstring>
#define MAXN 1010

using namespace std;

int n, m;
long long f[MAXN];
int a[MAXN];

long long funcao(int k){
	if (f[k]!=-1) return f[k];
	
	long long x;
	
	x=0;
	
	for(int i=1; i<=n; i++){
		x+=a[i]*funcao(k-i);
		x=x%m;
	}
	
	f[k]=x;
	
	return f[k];
}

int main(){
	int k;
	cin>>n>>k>>m;
	
	memset(f, -1, sizeof(f));
	
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) cin>>f[i];
	
	if(k>n){
		f[k]=funcao(k);	
	}
	
	cout<<f[k]<<"\n";
	
	return 0; 
}
