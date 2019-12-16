#include<iostream>

#define MAXN 1000

using namespace std;

int m[MAXN][MAXN];
int l[MAXN], c[MAXN];

int main(){
	int max=0, n;
	cin>>n;
	for(int i=0; i<n; i++){
		l[i]=0;
		for(int j=0; j<n; j++){
			cin>>m[i][j];
			l[i]+=m[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		c[i]=0;
		for(int j=0; j<n; j++){
			c[i]+=m[j][i];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(l[i]+c[j]-2*m[i][j]>max){
				max=l[i]+c[j]-2*m[i][j];
			}
		}
	}	
	
	cout<<max;
	return 0;
}
