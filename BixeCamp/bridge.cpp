#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 1001

int lis(vector<int> v){
      vector<int> pilha;

      fr(i, v.size()){
            auto it = upper_bound(pilha.begin(), pilha.end(), v[i]);

            if(it == pilha.end()) pilha.pb(v[i]);
            else (*it) = v[i];
      }

      return pilha.size();
}

int main(){
	   ios::sync_with_stdio(false);

     int tests;
     cin >> tests;

     while(tests--){
          int n;
          cin>> n;

          int bg[MAXN], end[MAXN];
          vector<pii> aux;

          fr(i, n) cin >> bg[i];
          fr(i, n) cin >> end[i];

          fr(i, n) aux.pb(mp(bg[i], end[i]));
          sort(aux.begin(), aux.end());

          vector<pii> v;

          fr(i, n) v.pb( mp(aux[i].second, i) );
          sort(v.begin(), v.end());

          vector<int> def;

          fr(i, n) def.pb(aux[i].second);

          cout << lis(def) << endl;
     }
}
