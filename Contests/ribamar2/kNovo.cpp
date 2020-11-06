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
typedef pair<long double, long double> ponto;
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

long double dp[2][1000], val[1000];

int getSumMask(int n){
	int ret = 0, i = 1;

	while(n > 0){
		if(n%2 == 1){
			ret+=i;
		}
		n/=2;
		i++;
	}

	return ret;
}

int getMask(string s){
	int m = 0;

	for(char x: s){
		m += (1 << (x - '1'));
	}

	return m;
}

int getSet(int mask){
	int ret = 0, dez = 1;
	frm(i, 9){
		if(((1 << i)&mask) != 0){
			ret+=(i+1)*dez;
			dez*=10;
		}
	}

	if(ret==0) ret = -1;

	return ret;
}

long double solve(int mask, int tipo){
	if(mask == 0) return 0.0;

	long double sum = 0.00000;

	int achou = 0;

	frr(d1, 6){
		frr(d2, 6){
			int somaDados = d1 + d2;
			long double ans = 0.000000;

			achou = 0;
			
			if(tipo == 0) ans = -1.0;
			else ans = 123456790.0;

			frr(i, 511){
				if(getSumMask(i) == somaDados && (i&mask) == i){
					long double aux = solve((i^mask), tipo);
					
					if(tipo == 0)
						ans = max(ans, aux);
					else
						ans = min(ans, aux);

					achou = 1;
				}
			}

			if(achou)sum += ans;
			else sum += (long double)getSet(mask);
		}
	}

	return sum/(long double)36;
}

void read(){
	string s;
	cin >> s;

	int mask = getMask(s);
	int d1, d2;

	cin >> d1 >> d2;
	int sum = d1 + d2;

	int maskMinimo = 0, maskMaximo = 0;
	long double maxVal = -1.0, minVal = 123456790.0;

	int achou = 0;

	frr(i, 511){
		//cout << i << " " << getSumMask(i) << endl;
		if(getSumMask(i) == sum && (i&mask) == i){
			long double aux = solve((i^mask), 0);
				
			if(maxVal < aux){
				maxVal = aux;
				maskMaximo = i;
			}

			aux = solve((i^mask), 1);

			if(minVal > aux){
				minVal = aux;
				maskMinimo = i;
			}

			achou = 1;
		}
	}

	if(achou){
		int ansMaximo, ansMinimo;

		ansMinimo = getSet(maskMinimo);
		ansMaximo = getSet(maskMaximo);

//		db;

		printf("%d %.5Lf\n", ansMinimo, minVal);

//		db;

		printf("%d %.5Lf\n", ansMaximo, maxVal);
	}
	else{
		cout << -1 << " ";
		cout << s << ".00000\n";
		cout << -1 << " ";
		cout << s << ".00000\n";
	}
}

int main(){
	ios::sync_with_stdio(false);

	mem(dp, -1);
	read();
}
