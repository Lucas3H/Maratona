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

#define MAXN 1000010
#define MOD 1000000007

vector<pii> divisors;
int ok[MAXN];

int main(){
	ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    for(int i = 2; i <= k; i++){
      if(k%i == 0){
        int e = 0;

        while(k%i == 0) {
          k /= i;
          e++;
        }

        divisors.pb(mp(i, e));
      }
    }

    int a[MAXN];
    fr(i, n) cin >> a[i];

    fr(i, divisors.size()){
      fr(j, n){
        int e = 0, aux = a[j], p = divisors[i].first;

        while(aux%p == 0){
          aux /= p;
          e++;
        }

        if(e >= divisors[i].second) {
          ok[i] = 1;
          continue;
        }
      }
    }

    fr(i, divisors.size()){
      if(ok[i] == 0){
        cout << "No" << endl;
        return 0;
      }
    }

    cout << "Yes" << endl;
    return 0;
}
