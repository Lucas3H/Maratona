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

struct Query{
	int sa, ea, sb, eb;
};

int t[2*MAXN];
Query q[MAXN];
int bit[2][2*MAXN];
int n;
	
pii aux[2*MAXN];

void update(int i, int val, int tipo){
    while(i <= 2*n){
        bit[tipo][i] += val;
        i += i & (-i);
    }
}

int query(int i, int tipo){
    int sum = 0;

    while(i > 0){
        sum += bit[tipo][i];
        i -= i & (-i);
    }

    return sum;
}

pii y[2*MAXN], x[2*MAXN];

int main(){
	ios::sync_with_stdio(false);

	cin >> n;

	frr(i, n){
		cin >> q[i].sa >> q[i].ea >> q[i].sb >> q[i].eb;
		
		aux[2*i - 1] = mp(q[i].sa, -i);
		aux[2*i] = mp(q[i].ea, i);
	}

	sort(aux + 1, aux + 2*n + 1);
	frr(i, 2*n){
		t[i] = aux[i].s;

		if(aux[i].s < 0){
			x[-aux[i].s].f = i;
		}
		else{
			x[aux[i].s].s = i;
		}
	}

	frr(i, n){
		aux[2*i - 1] = mp(q[i].sb, -i);
		aux[2*i] = mp(q[i].eb, i);
	}

	sort(aux + 1, aux + 2*n + 1);
	frr(i, 2*n){
		if(aux[i].s < 0){
			y[-aux[i].s].f = i;
		}
		else{
			y[aux[i].s].s = i;
		}
	}

	//frr(i, n) cout << x[i].f << " " << x[i].s << endl;

	int deu = 1;

	frr(i, 2*n){
		int ind;
		if(t[i] > 0){
			ind = t[i];

			update(x[ind].f, -1, 0);//0 começa
			update(x[ind].s, -1, 1);//1 termina
		}
		else{
			ind = -t[i];

			if(query(y[ind].f - 1, 1) > 0){
				deu = 0;
				break;
			}
			else if(query(2*n, 0) - query(y[ind].s, 0) > 0){
				deu = 0;
				break;
			}
			else{
				update(y[ind].f, 1, 0);//0 começa
				update(y[ind].s, 1, 1);//1 termina
			}
		}
	}

	if(deu) cout << "YES\n";
	else cout << "NO\n";
}
