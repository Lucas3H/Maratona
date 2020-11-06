#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

bool check_bit(int x, int i){
	bool resp = ( x&(1 << i) != 0 );
	return resp; 
}

// lsb - largest significant bit
int lsb(int x){
	return x&-x ;
}

int count_bits(int x){
	int resp = 0;
	while(x != 0){
		resp++;
		x -= lsb(x);
	}

	return resp;
}

bool is_power_of_two(int x){
	if(x == 0) return 0;
	else return (x&(x-1) == 0);
	/*
	if(count_bits(x) == 1) return 1;
	else return 0;	
	 */
}

int ligar_bit(int x, int i){
	x = x | (1 << i);
	return x;
}

int desligar_bit(int x, int i){
	x |= (1 << i);
	x ^= (1 << i);

	return x;
}

int main(){
	int x, i;
	cin >> x >> i;

	cout << "Checar bit: " << check_bit(x, i) << endl;
	cout << "Largest significant bit: " << lsb(x) << endl;
	cout << "Soma dos bits: " << count_bits(x) << endl;
	cout << "É potencia de dois? " << is_power_of_two(x) << endl;
	cout << "Ligar bit : " << ligar_bit(x, i) << endl;
	cout << "Desigar bit : " << desligar_bit(x, i) << endl;
	cout << "Complemento de 1: " << ~(x) << endl;

	return 0;
}