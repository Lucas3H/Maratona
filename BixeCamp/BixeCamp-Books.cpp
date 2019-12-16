#include <iostream>
#include <cmath>
using namespace std;

int books, time;
int b[100010];
long long t[100010];

int bin(int temp){
	int ini = 0, fim = books+1;
	
	int meio;
	
	while(ini <= fim){
		meio = (ini+fim)/2;
		
		if(t[meio] > temp) fim=meio;
		else if(t[meio+1] <= temp ) ini=meio+1;
		else break;
	}
	
	return meio;
}

int main(){
	
	cin >> books >> time;
	
	t[0] = 0;
	t[books+1] = 2*pow(10,9)+1;
	
	for(int i=0; i<books; i++){
		cin >> b[i];
		t[i+1] = t[i]+b[i];
	}
	
	int max=0, beg=0, end=time;
	
	while(beg < books){
		if(max < bin(end)-beg) max = bin(end) - beg;
		
		end+=b[beg];
		
		beg++;
	}
	
	cout << max << endl;
	
}
