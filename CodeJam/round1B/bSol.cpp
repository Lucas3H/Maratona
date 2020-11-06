// 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000000
#define MAXL 30
#define ROOT 1
#define INF 987654321

ll x[110], y[110], r = MOD - 5, a, b;

int main(){
	ll t = 100;
	frr(i, t){
		x[i] = random()%(5);
		y[i] = random()%(5);
	}
	
	FILE * arq = fopen("in", "w"), * resp = fopen("ordem", "w");

	cout << t << ' ' << r << " " << r << endl;

	frr(i, t){
		ll deu = 0;
		frr(j, 300){
			cin >> a >> b;

			fprintf(resp, "%lld %lld\n", a, b);

			if(a == x[i] && b == y[i]){
				cout << "CENTER" << endl;
				fprintf(resp, "CENTER\n");
				deu = 1;
				break;
			}
			else if((a - x[i])*(a - x[i]) + (b - y[i])*(b - y[i]) <= r*r){
				fprintf(resp, "HIT\n");
				cout << "HIT" << endl;
			}
			else{
				fprintf(resp, "MISS\n");
				cout << "MISS" << endl;
			}
		}

		if(deu == 0){
			fprintf(arq, "%lld %lld\n", x[i], y[i]);
			break;
		}
	}

	fclose(arq);
	fclose(resp);
}
