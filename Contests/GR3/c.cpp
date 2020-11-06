#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 300010

int main(){
	int n;
	cin>> n;
	int v[MAXN];

	frr(i, n) cin >> v[i];

	int trocas = 0;
	int i = 1;
	vector<pii> resp;
	while(i < n){
		if(v[i] == i){
			i++;
			continue;
		}

		if(v[i] - i >= n/2){
			resp.pb(mp(v[i], i));
			swap(v[i], v[v[i]]);
			trocas++;
		}
		else if(i <= n/2 && v[i] <= n/2){
			resp.pb(mp(i, n));
			resp.pb(mp(v[i], n));
			int aux = v[i];

			swap(v[i], v[n]);
			swap(v[aux], v[n]);
			trocas+=2;
		}
		else if(i > n/2 && v[i] > n/2){
			resp.pb(mp(i, 1));
			resp.pb(mp(v[i], 1));
			resp.pb(mp(i, 1));
			
			int aux = v[i];
			trocas+=3;
			
			swap(v[i], v[1]);
			swap(v[aux], v[1]);
			swap(v[i], v[1]);
		}
		else{
			resp.pb(mp(i, n));
			resp.pb(mp(n, 1));
			resp.pb(mp(1, v[i]));
			resp.pb(mp(1, n));
		
			int aux = v[i];
			trocas+=4;
		
			swap(v[i], v[n]);
			swap(v[n], v[1]);
			swap(v[1], v[aux]);
			swap(v[1], v[n]);
		}
	}

	cout << trocas << endl;
	fr(i, trocas) cout << resp[i].first << " " << resp[i].second << endl;
}