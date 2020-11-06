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

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	set<int> pequenos;
	int menor_que_saiu = 0, val_menor_que_saiu = MOD;
	int maior_que_saiu = 0, val_maior_que_saiu = 0;
	int davez, val_davez;
	
	frr(i, k-1) pequenos.insert(i);


	for(int i = k; i <= n; i++){
		pequenos.insert(i);

		cout << "? ";
		for(auto x: pequenos) cout << x << " ";
		cout << endl;
		cin >> davez >> val_davez;

		if(val_davez < val_menor_que_saiu){
			val_menor_que_saiu = val_davez;
			menor_que_saiu = davez;
		}
		if(val_davez > val_maior_que_saiu){
			val_maior_que_saiu = val_davez;
			maior_que_saiu = davez;
		}

		pequenos.erase(davez);
	}

	/*pequenos.insert(maior.s);*/

	pequenos.insert(menor_que_saiu);

	int pos, val;

	int sairam = 0;

	set<int> aux;
	for(auto x: pequenos) aux.insert(x);

	for(auto x: aux){
		if(x == menor_que_saiu) continue;
		pequenos.erase(x);
		pequenos.insert(maior_que_saiu);

		cout << "? ";
		for(auto y: pequenos) cout << y << " ";
		cout << endl;

		cin >> pos >> val;
		if(pos != menor_que_saiu) sairam++;

		pequenos.erase(maior_que_saiu);
		pequenos.insert(x);
	}
	/*frr(i, k - 1){
		//cout << "OL\n";
		cout << "? ";
		for(auto x: pequenos) cout << x << " ";
		cout << endl;
		cin >> pos >> val;

		if(pos <= k) sairam++;

		pequenos.erase(pos);
		
		pii maior = saiu.top();
		saiu.pop();
		pequenos.insert(maior.s);

		davez = pos;
		val_davez = val;
	}*/

	cout << "! " << sairam + 1 << endl;

}
