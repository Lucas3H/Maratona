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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int comeca[MAXN*10];
int termina[10*MAXN];

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	fr(i, n){
		int m;
		cin >> m;

		int v[MAXN];

		fr(i, m) cin >> v[i];
	
		int deu = 1;
		fr(i, m-1){
			if(v[i] < v[i+1]){
				deu = 0;
				break;
			}
		}

		if(deu){
			comeca[v[0]]++;
			termina[v[m-1]]++;
		}
	}

	frr(i, 1000000){
		comeca[i] = comeca[i-1] + comeca[i];
	}

	ll ans = (ll)0;
	fr(i, 1000001){
		if(termina[i]){
			ans += (ll)termina[i]*((ll)comeca[i]);
			//cout << i << " " << termina[i] << " " << comeca[i]<< endl; 
		}	
	}

	//cout << ans << endl;

	cout << (ll)n*((ll)n) - ans << endl;
}
