#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 1000010

int main(){
	int q;
	cin >> q;

	int primo[MAXN+10];
	fr(i, MAXN) primo[i] = 1;
	vector<int> prime;

	for(int i = 2; i <= MAXN; i++){
		if(primo[i]){
			// << "P " << i << endl;
			for(int j = 2; i*j <= MAXN; j++) primo[i*j] = 0;
			prime.pb(i);
		}
	}


	while(q--){
		int n;
		ll d[305];
		cin >> n;

		fr(i, n) cin >> d[i];

		sort(d, d+n);

		ll num = d[0]*d[n-1];

		vector<ll> primos_div;

		int j = 0;
		if(d[n-1]%d[0] != 0) primos_div.pb(d[0]);

		while(prime[j] <= d[n-1]){
			if(d[n-1]%prime[j] == 0){
				primos_div.pb(prime[j]);
		//		cout << "FF "<< prime[j] << endl;
			}
			j++;
		}

		int div = 1;

		fr(i, primos_div.size()){
			ll p = primos_div[i];

			int resp = 0;
			
		//	cout << L << " primo " << p;
			while(num%p == 0){
				resp++;
				p *= primos_div[i];
			}

			//cout << " " << num << " " << p << " "<< resp << endl;

			div *= (resp+1);
		}

		int deu = 1;

		fr(i, n){
			if(num%d[i] != 0){
				deu = 0;
				break;
			}
		}

		if(deu && div == n + 2) cout << num << endl;
		else cout << -1 << endl;

	}
}