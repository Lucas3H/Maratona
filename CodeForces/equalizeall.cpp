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

#define MAXN 200010

int main(){
	int n;
	cin >> n;

	int fr[MAXN];
	mem(fr, 0);

	int a[MAXN];
	fr(i, n){
		cin >> a[i];
		fr[a[i]]++;
	}

	int maior = 0, ind_maior = 0;

	fr(i, MAXN){
		if(fr[i] > maior){
			maior = fr[i];
			ind_maior = i;
		}
	}

	cout << n - maior << endl;

	maior = ind_maior;


	fr(i, n){
		if(a[i] == ind_maior){
			ind_maior = i;
			break;
		}
	}

	for(int i = ind_maior + 1; i < n; i++){
		if(a[i] == maior) continue;

		if(a[i] > maior) cout << 2 <<" "<< i+1 << " " << i<< endl;
		if(a[i] < maior) cout << 1 <<" "<< i+1 << " " << i<< endl;
	}

	for(int i = ind_maior - 1; i >= 0; i--){
		if(a[i] == maior) continue;

		if(a[i] > maior) cout << 2 <<" "<< i+1 << " " << i+2<< endl;
		if(a[i] < maior) cout << 1 <<" "<< i+1 << " " << i+2<< endl;
	}
}