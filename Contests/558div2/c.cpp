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

#define MAXN 52

pii inclinacao(pii a, pii b){
	int num = a.second - b.second;
	int den = a.first - b.first;

	if(num == 0) return mp(0, 1);

	if(den == 0) return mp(0, 0);

	if(den < 0){
		den = -den;
		num = -num;
	}

	int d = __gcd(abs(num), abs(den));

	num/=d;
	den/=d;

	return mp(num, den);
}

pii eixo_y(pii a, pii b){
	pii inc = inclinacao(a, b);

	if(inc == mp(0, 0)) return inc;

	int num = a.second*inc.second - a.first*inc.first;
	int den = inc.second;


	if(num == 0) return mp(0, 1);

	if(den == 0) return mp(0, 0);

	if(den < 0){
		den = -den;
		num = -num;
	}

	int d = __gcd(abs(num), abs(den));

	num/=d;
	den/=d;

	return mp(num, den);
}

int main(){
	int n;
	cin >> n;

	set<pair<pii, pii>> s;

	pii ponto[MAXN];

	fr(i, n){
		int x, y;
		cin >> x >> y;

		ponto[i] = mp(x, y);
	}

	int resp = 0;
	fr(i, n){
		for(int j = i + 1; j < n; j++){
			pair<pii, pii> R = mp(inclinacao(ponto[i], ponto[j]), eixo_y(ponto[i], ponto[j]));
			s.insert(R);

			for(auto x: s){
				if(x.first != R.first) {
					resp++;
					//cout << ponto[i].first << " " << ponto[i].second << " " << ponto[j].first << " " << ponto[j].second << endl;  
					cout << x.second.first << "/" << x.second.second << " " << R.second.first << "/" << R.second.second << endl;
				}
			}
		}
	}

	cout << resp << endl;
}