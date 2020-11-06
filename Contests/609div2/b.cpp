#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	int m;
	cin >> m;

	map<int, int> a, b;
	set<int> ap, bp;
	int aux;
	int menor = MOD;

	frr(i, n) {
		cin >> aux;
		ap.insert(aux);
		a[aux]++;

		menor = min(menor, aux);
	}
	frr(i, n) {
		cin >> aux;
		b[aux]++;

		bp.insert(aux);
	}

	int menor_dif = MOD;

	for(auto x: bp){
		int dif = (x - menor + m)%m;
		int deu = 1;

		for(auto y: ap){
			if(b[(dif + y)%m] != a[y]){
				deu = 0;
				break;
			}
		}

		if(deu){
			menor_dif = min(menor_dif, dif);
		}
	}

	cout << menor_dif << endl;
}	
