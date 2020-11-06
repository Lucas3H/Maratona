// https://codeforces.com/contest/13/problem/E
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
#define MAXL 30
#define ROOT 1

int n, m, len;
int prox[MAXN], passos[MAXN];
int jmp[MAXN];

void update(int pos, int j){
	if(pos + j >= n){
		prox[pos] = n;
		passos[pos] = 1;
	}
	else if(floor((pos + j)/len) == floor((pos)/len)){
		prox[pos] = prox[pos + j];
		passos[pos] = passos[pos + j] + 1;
	}
	else{
		prox[pos] = pos + j;
		passos[pos] = 1;
	}
}

pii query(int pos){
	//cout << pos << endl;
	//cout << passos[pos] << endl;
	if(prox[pos] == n){
		int it = pos, ans = 0;
		while(it + jmp[it] < n){
			ans++;
			it = it + jmp[it];
		}
		
		return mp(it, ans + 1);
	}
	else{
		pii aux = query(prox[pos]);
		return mp(aux.f, aux.s + passos[pos]);
	}
}

int main(){

	scanf("%d %d", &n, &m);
	len = (int)sqrt(n + .0) + 1;
	fr(i, n) scanf("%d", &jmp[i]);

	frm(i, n) update(i, jmp[i]);

	//fr(i, n) cout << prox[i] <<" " << passos[i] << endl;

	int a, b, c;

	fr(i, m){
		scanf("%d %d", &a, &b);
		b--;

		if(a == 0){
			scanf("%d", &c);

			jmp[b] = c;

			int l = floor(b/len)*len;

			for(int j = b; j >= l; j--){
				update(j, jmp[j]);
			}
		}
		else {
			pii aux = query(b);
			printf("%d %d\n", aux.f + 1, aux.s);
		}
	}
}
