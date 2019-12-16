#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 300010


int r[MAXN];

int n, m;

bool ehpossivel(int mov){
	int ant = 0;
	fr(i, n){
		//cout << ant << endl;

		int ini = r[i], fim = (r[i] + mov)%m;

		//cout << ini << " " << fim << endl;

		if(r[i] + mov < m){
			if(ant <= r[i]) ant = r[i];
			else if(ant > r[i] && ant > fim) return 0;
			else if(ant > r[i] && ant <= fim){
			//	cout << "OKOKOK " << i << endl;
			}
		}
		else{
			if(ant <= fim) continue;
			else if(ant > fim && ant > r[i]) continue;
			else if(ant > fim && ant <= r[i]) ant = r[i];
		} 
	}

	return 1;
}

int main(){
	cin >> n >> m;

	fr(i, n) cin >> r[i];

	int ini = 0, fim = m-1, meio = 0, fator = 64;

	while(ini <= fim && fator > 0){
		meio = (ini + fim)/2;

		//cout << meio << " " << ehpossivel(meio) << endl;

		if(ehpossivel(meio)) fim = meio;
		else ini = meio;

		fator--;
	}

	//cout << ehpossivel(4)

	if(ehpossivel(meio)) cout << meio << endl;
	else cout << meio+1 << endl;

}