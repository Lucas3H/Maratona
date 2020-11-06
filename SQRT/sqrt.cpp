// 
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

/*
	Estrutura de dados que faz a mesma coisa que a Segtree, com query em O(sqrt(n)) e update em O(1).
*/

ll n, len;
vector<ll> a, b;

ll query(int l, int r){
	ll sum = 0;
    for (int i=l; i<=r;){
        if (i % len == 0 && i + len - 1 <= r) {
            sum += b[i / len];
            i += len;
        }
        else {
            sum += a[i];
        	i++;
        }
	}

	return sum;
}

void build(){
	ll aux;
	a.clear();
	b.clear();

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> aux;
		a.push_back(aux);
	}

	len = (int) sqrt (n + .0) + 1; 

	int i = 0;
	ll sum;
	while(i < n){
		sum = 0;
		for(int j = 0; j < len && i < n; i++){
			sum+=a[i++];
		}

		b.push_back(sum);
	}
}

int main(){
	ios::sync_with_stdio(false);
}
