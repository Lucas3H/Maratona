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
typedef pair<ll, ll> pll;
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
#define INF 1000000000000000100

int a[MAXN];
string s;		

int main(){
	ios::sync_with_stdio(false);

	freopen("stations.in", "r", stdin);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		cin >> s;
		
		vector<int> gas;
	
		fr(i, s.size()){
			if(s[i] == '+') gas.pb(i + 1);
		}
	
		int ans = n;

		if(gas.size() == 1){
			cout << n/2 << endl;
			continue;
		}
		else if(gas.size() == 2){
			for(int i = 0; i < gas.size(); i++){
				int left = gas[0] - 1, right = (n - gas.back());

				if(i == 0){
					left = gas[1] - 1;
				}
				else if(i == gas.size() - 1){
					right = n - gas[gas.size() - 2];
				}

				/*Coloca na esq*/
				int maior = 0;
				maior = max(maior, (left + 1)/3);
				maior = max(maior, right);
		
				ans = min(ans, maior);

				/*Coloca na dir*/
				maior = 0;

				maior = max(maior, left);
				maior = max(maior, (right + 1)/3);
	
				ans = min(ans, maior);
			}
			cout << ans << endl;
			
			continue;
		}

		set<tuple<int, int, int>> meio;
		for(int i = 0; i < gas.size() - 1; i++){
			meio.insert({-(gas[i + 1] - gas[i]), i, i + 1});
		}

		/*
		extremos é (k + 1)/3
		meio é (k + 1)/4;
		*/

		/*
		for(auto x: meio){
			cout << get<0>(x) << ' ';
		}
		*/

		for(int i = 0; i < gas.size(); i++){
			int left = gas[0] - 1, right = (n - gas.back());

			if(i == 0){
				left = gas[1] - 1;
				meio.erase({-(gas[1] - gas[0]), 0, 1});
			}
			else if(i == gas.size() - 1){
				right = n - gas[gas.size() - 2];
				meio.erase({-(gas[gas.size() - 1] - gas[gas.size() - 2]), gas.size() - 2, gas.size() - 1});
			}
			else{
				meio.erase({-(gas[i] - gas[i-1]), i-1, i});
				meio.erase({-(gas[i + 1] - gas[i]), i, i + 1});
				/*
				db;
				cout << -(gas[i + 1] - gas[i-1]) << " entra " << i-1 << " " << i + 1 << endl;
				*/
				meio.insert({-(gas[i + 1] - gas[i-1]), i-1, i + 1});
			}

			/*Coloca na esq*/
			int maior = 0, aux, l, r;
			tuple<int, int, int> tup = (*meio.begin());
			tie(aux, l, r) = tup;
			aux = -aux;

			maior = max(maior, (left + 1)/3);
			maior = max(maior, right);
			maior = max(maior, (aux)/2);

			//cout << i << " left " << maior << " " << aux << " " << r << endl;

			ans = min(ans, maior);

			/*Coloca na dir*/
			maior = 0;

			maior = max(maior, left);
			maior = max(maior, (right + 1)/3);
			maior = max(maior, (aux)/2);

			//cout << i << " right " << maior << " " << (right + 1)/3 << " " << left << " " << (aux)/2 << endl;

			ans = min(ans, maior);

			/*Coloca no meio*/
			maior = 0;

			meio.erase({-aux, l, r});
			meio.insert({-(   (aux + 1)/2     ), -1, -1});

			int davez, L, D;
			tup = (*meio.begin());
			tie(davez, L, D) = tup;
			davez = -davez;

			maior = max(maior, left);
			maior = max(maior, right);
			maior = max(maior, (davez)/2);
		
			//cout << i << " meio	 " << maior << endl;

			ans = min(ans, maior);

			/*conserta meio*/
			meio.erase({-(   (aux + 1)/2     ), -1, -1});
			meio.insert({-aux, l, r});

			if(i == 0){
				meio.insert({-(gas[1] - gas[0]), 0, 1});
			}
			else if(i == gas.size() - 1){
				meio.erase({-(gas[gas.size() - 1] - gas[gas.size() - 2]), gas.size() - 2, gas.size() - 1});
			}
			else{
				//db;
				//cout << -(gas[i + 1] - gas[i-1]) << " sai " << i-1 << " " << i + 1 << endl;
				meio.erase({-(gas[i + 1] - gas[i-1]), i-1, i+1});
				meio.insert({-(gas[i] - gas[i-1]), i-1, i});
				meio.insert({-(gas[i + 1] - gas[i]), i, i+1});
			}

			/*
			for(auto x: meio){
				cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << " | ";
			}
			cout << endl;
			*/
			//cout << t << " " << ans << endl;	
		}

		
		//cout << s << endl;
		cout << ans << endl;
		
	}
}
