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

int bit[MAXN][3];
int n;

void update(int i, int val, int t){
    while(i <= n){
        bit[i][t] += val;
        i += i & (-i);
    }
}

int query(int i, int t){
    int sum = 0;

    while(i > 0){
        sum += bit[i][t];
        i -= i & (-i);
    }

    return sum;
}

void build(int t, int v[], int tam){
    fr(i, n + 1) bit[i][t] = 0;
    frr(i, tam) update(v[i], 1, t);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;

	int p[2*MAXN], a[2*MAXN], pos[2*MAXN], inv[2*MAXN];
	frr(i, n){
		cin >> p[i];
		a[i] = p[i];

		pos[p[i]] = i; 
	}

	int aux[2*MAXN];
	
	for(int i = pos[1] - 1; i > 0; i--){
		aux[pos[1] - i] = pos[i];
	}
	build(0, aux, pos[1] - 1);
	frr(i, pos[1] - 1){
		update(aux[i], -1, 0);
		inv[aux[i]] = query(aux[i], 0);
	}

	for(int i = pos[1] + 1; i <= n; i++){
		aux[i - pos[1]] = pos[i];
	}
	build(1, aux, n - pos[1]);
	frr(i, n - pos[1]){
		update(aux[i], -1, 1);
		inv[aux[i]] = query(aux[i], 1);
	}
/*
	cout << "inV" << endl;

	frr(i, n) cout << inv[i] << " ";
	cout << endl;
*/
    fr(i, n + 1) bit[i][2] = 0;
    frr(i, n) update(i, 1, 2);

	int ant = 0;
	cout << 0 << " ";

	for(int i = 2; i <= n; i++){
		if(pos[i] > pos[1]){
			update(pos[i], -1, 2);

			int q1 = query(pos[i], 2), q2 = query(pos[1], 2);
			cout << ant + q1 - q2 << " ";
			update(pos[1], 1, 2);

			ant = ant + q1 - q2;
		}
		else{
			update(pos[i], -1, 2);

			int q1 = query(pos[i], 2), q2 = query(pos[1], 2);
			//cout << q1 << " " << q2 << " ";
			cout << ant + q2 - q1 - inv[i] << " ";
			update(pos[1],1 , 2);


			ant = ant + q2 - q1 - inv[i];
		}
	}
}
