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

#define MAXN 10000010
#define MOD 1000000007

int prime[MAXN];
vector<int> p;

void crivo(){
  for(int i = 2; i <MAXN; i++){
    if(prime[i] == 0){
      p.pb(i);
      for(int j = 2*i; j < MAXN; j+=i) prime[j] = 1;
    }
  }
}

int pai[MAXN], peso[MAXN];

int find(int x){
  if(pai[x] == x) return x;
  else return pai[x] = find(pai[x]);
}

void join(int a, int b){
  a = find(a);
  b = find(b);

  if(a == b) return;

  if(peso[a] < peso[b]) swap(a, b);

  pai[b] = a;
  peso[a] += peso[b];
}

int main(){
		ios::sync_with_stdio(false);
    int tests;
    cin >> tests;

    crivo();

    ll A, B, P;

    fr(ts, tests){
      cin >> A >> B >> P;
      int n = B - A;

      fr(i, n+1){
        pai[i] = i;
        peso[i] = 1;
      }

      if(P > MAXN){
        cout << n+1 << endl;
        continue;
      }

      int ini = lower_bound(p.begin(), p.end(), (int)P) - p.begin();

      for(int i = ini; i < p.size(); i++){
        int q = p[i];
        int r = A%q;

        if(r != 0) r = q - r;

        for(int j = r; j < n+1; j += q){
          //if(j == 8) cout << q << " OKOK" << endl;
          join(r, j);
        }
      }

      int ans = 0;
      fr(i, n+1){
    //    cout <<i << " " << find(i) << endl;
        if(find(i) == i){
          ans++;
          //cout << i << endl;
        }
      }

      cout << "Case #" << ts+1 << ": " << ans << endl;
    }
}
