#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007


int a[3*MAXN], b[3*MAXN], A[3*MAXN], B[3*MAXN];
int a1[3*MAXN], a2[3*MAXN], b1[3*MAXN], b2[3*MAXN];


int soma(int x){

	int s = 0;

	while(x > 0){ // vamos reduzindo x até acabarmos (quando chegamos a zero)
		s += A[x]; // adicionamos o pedaço de árvore atual à soma
		x -= (x & -x);  // removemos o bit menos significante
	}

	return s;
}

int sum(int x){

	int s = 0;

	while(x > 0){ // vamos reduzindo x até acabarmos (quando chegamos a zero)
		s += B[x]; // adicionamos o pedaço de árvore atual à soma
		x -= (x & -x);  // removemos o bit menos significante
	}

	return s;
}

int main(){
		ios::sync_with_stdio(false);

		int t;
		cin >> t;
		int n;


		while(t--){
			cin >> n;

			frr(i, n) A[i] = 0;
			frr(i, n) B[i] = 0;

			frr(i, n) cin >> a[i];

			frr(i, n){
				A[a[i]]++;
				a1[i] = soma(a[i]-1);
			}

			frr(i, n) A[i] = 0;
			frr(i, n){
				A[n-a[i]]++;
				a2[i] = soma(a[i]-1);
			}

			frr(i, n) cin >> b[i];

			frm(i, n+1){
				B[b[i]]++;
				b1[i] = sum(b[i]-1);
			}

			frr(i, n) B[i] = 0;
			frm(i, n+1){
				B[n-b[i]]++;
				b2[i] = sum(b[i]-1);
			}

			int no = 0;
			frr(i, n){
				if((a1[i] != b1[i]) || (a2[i] != b2[i])){

					cout << t << " OKO " << i << endl;
					no = 1;
					break;
				}
			}

			if(no){
				cout << "NO" << endl;
			}
			else cout << "YES" << endl;

		}
}
