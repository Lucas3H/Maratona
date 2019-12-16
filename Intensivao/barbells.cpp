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

vector<pii> pl;
int b[15], p[15];

set<int> valid;

int sum(int x){
  int ans = 0, i=0;
  while(x > 0){
    ans += (x%2)*p[i];
    x/=2;
    i++;
  }

  return ans;
}

int main(){
		ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    fr(i, n) cin >> b[i];
    fr(i, m) cin >> p[i];

    fr(i, 1 << m){
      pl.pb(mp(sum(i), i));
    }

    sort(pl.begin(), pl.end());

//    fr(i, pl.size()) cout << pl[i].first << endl;

    int ini = 0, fim = 0;

    while(ini < pl.size()){
      while(pl[fim].first == pl[ini].first) fim++;

      int deu = 0;
      for(int i = ini; i < fim; i++){
        for(int j = i; j < fim; j++){
          //cout << (pl[i].second)^(pl[j].second) << " " << (pl[i].second)|(pl[j].second) << endl;

          if(((pl[i].second)^(pl[j].second)) == ((pl[i].second)|(pl[j].second))){
              valid.insert((pl[i].second)^(pl[j].second));
            //  cout << sum((pl[i].second)^(pl[j].second)) << endl;
              deu = 1;
              break;
          }
        }

        if(deu == 1)break;
      }

      //cout << fim << endl;

      ini = fim;
    }
    set<int> ok;


    //for(auto x: valid) cout << sum(x) << endl;

    for(int i = 0; i < n; i++){
      for(auto x: valid){
        ok.insert(b[i] + sum(x));
      }
    }

    for(auto x: ok) cout << x << endl;
}
