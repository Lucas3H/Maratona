// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=588&page=show_problem&problem=4450
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

#define MAXN 50010
#define p1 1000000007
#define p2 1000000009
#define p3 1000000021
#define np 1

ll p[np] = {p1};

ll Exp[50010][np];

ll solve(char t[], int ini, int fim){
	if(ini == fim) return (ll)1;
	if(ini > fim) return (ll)0;

	ll r[3] = {0, 0, 0}, l[3] = {0, 0, 0};
	int i = ini, j = fim;

	while(i <= j){
		fr(k, np){
			l[k] = (l[k] + (t[i-1] - 'A' + 1)*Exp[i - ini][k])%p[k];
			r[k] = (27*r[k])%p[k];
			r[k] = (t[j-1] - 'A' + 1 + r[k])%p[k];
		}

		i++;
		j--;	

		if(l[0] != r[0]) continue;
		//if(l[1] != r[1]) continue;
		//if(l[2] != r[2]) continue;

		return 2 + solve(t, i, j);
	}

	return (ll)1;
}

int main(){
	int T;
	scanf("%d", &T);

	fr(i, np){
		Exp[0][i] = 1;

		Exp[1][i] = 27;

		for(int j = 2; j < 50010; j++){
			Exp[j][i] = (Exp[j-1][i]*Exp[1][i])%p[i];
		}
	}

	char t[50010];
	frr(ts, T){
		scanf("%s", t);

		printf("Case #%d: %lld\n", ts, solve(t, 1, strlen(t)));
	}
}
