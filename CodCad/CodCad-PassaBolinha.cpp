#include<iostream>

using namespace std;

int main(){
	 int n, x, y, total=1;
	 int a[102][102], b[102][102], C[102][102], L[102][102];
	 cin>>n;
	 cin>>x>>y;
	 
	 for(int i=1; i<=n; i++){
	 	for(int j=1; j<=n; j++){
	 		cin>>a[i][j];
	 		b[i][j]=0;
		 }
	 }
	 
	 for(int i=1; i<=n; i++){
	 	a[i][0]=0;
	 	a[0][i]=0;
	 	a[i][n+1]=0;
	 	a[n+1][i]=0;
	 	b[i][0]=0;
	 	b[0][i]=0;
	 	b[i][n+1]=0;
	 	b[n+1][i]=0;
	 }
	 
	 b[x][y]=1;
	 C[x][y]=0;
	 L[x][y]=0;
	 int l=x, c=y;
	 
	 while(l!=0){
	 	
	 	if(a[l][c]<=a[l-1][c] && b[l-1][c]==0){
	 		L[l-1][c]=l;
	 		C[l-1][c]=c;
	 		b[l-1][c]++;
	 		l--;
	 		total++;
	 		continue;
		}
		else if(a[l][c]<=a[l][c+1] && b[l][c+1]==0){
		 	L[l][c+1]=l;
	 		C[l][c+1]=c;
		 	b[l][c+1]++;
		 	c++;
		 	total++;
		 	continue;
		}
		else if(a[l][c]<=a[l+1][c] && b[l+1][c]==0){
		 	L[l+1][c]=l;
	 		C[l+1][c]=c;
		 	b[l+1][c]++;
		 	l++;
		 	total++;
		 	continue;
		}
		else if(a[l][c]<=a[l][c-1] && b[l][c-1]==0){
		 	L[l][c-1]=l;
	 		C[l][c-1]=c;
		 	b[l][c-1]++;
		 	c--;
		 	total++;
		 	continue;
		}
		else{
			int A=l, B=c;
			l=L[A][B];
			c=C[A][B];
		}
	 }
	 
	 cout<<total;
}
