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

int soma[MAXN], a[MAXN], num[MAXN];

void atualiza(int v, int i, int j){
	if(i == j) {
		soma[v] = a[i];
		num[v] = 1;
	}
	else{
		int meio = (i+j)/2;

		atualiza(2*v+1, i, meio);
		atualiza(2*v+2, meio+1, j);

		soma[v] = soma[2*v+1] + soma[2*v+2];
		num[v] = num[2*v + 1] + num[2*v+2];
	}
}

pii consulta(int v, int i, int j, int a, int b){
	if(a <= i && j <= b) return mp(soma[v], num[v]);

	if(a > j || b < i) return mp(0, 0);

	int meio = (i+j)/2;

	pii left = consulta(2*v+1, i, meio, a, b);
	pii right = consulta(2*v+2, meio+1, j, a, b);

	if(left.first > 0 && right.first > 0){
		return mp(left.first+right.first, left.second + right.second);
	}
	else if(left.first > 0 && right.first < 0){
		return left;
	}
	else if(left.first < 0 && right.first > 0){
		return righ;t
	}

}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		mem(soma, 0);
		mem(num, 0);

		fr(i, n) cin >> a[i];
		atualiza(0, 0, n);

		int q;
		cin >> q;

		fr(i, q){
			int a, b;
			cin >> a >> b;

			cout << "Resposta: " << consulta(0, 0, n, a, b).first << " " << consulta(0, 0, n, a, b).second << endl;
		}
	}
}