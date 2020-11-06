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

int main(){
		ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    ll adiciona[MAXN], start[MAXN], end[MAXN];
    ll a[MAXN];

    frr(i, n) cin >> a[i];

    frr(i, m) cin >> start[i] >> end[i] >> adiciona[i];

    int comeco[MAXN], fim[MAXN];
    int x, y;
    fr(i, k){
      cin >> comeco[i] >> fim[i];
    }

    sort(comeco, comeco+k);
    sort(fim, fim + k);

    ll sum = 0;
		ll j = 0, l = 0;
    frr(i, m){
      while(j < k && comeco[j] == i){
        sum++;
        j++;
      }
      while(l < k && fim[l] == i - 1){
        sum--;
        l++;
      }

//			cout << sum << " sum " << adiciona[i] << endl;
      adiciona[i] *= sum;
    }

/*
		cout << "-------------------" << endl;
		frr(i, m) cout << adiciona[i] << " ";
		cout << "-------------------" << endl;
*/
    pair<ll, ll> ad[MAXN], di[MAXN];

    frr(i, m){
      ad[i] = mp(start[i], adiciona[i]);
      di[i] = mp(end[i], adiciona[i]);
    }

    sort(ad+1, ad+m+1);
    sort(di+1, di+m+1);

    sum = 0, j = 1, l = 1;

    frr(i, n){
      while(ad[j].first == i) {
				sum += ad[j].second;
				j++;
			}
			while(di[l].first == i - 1) {
				sum -= di[l].second;
				l++;
			}
      a[i] += sum;
    }

    frr(i, n) cout << a[i] << " ";

    cout << endl;
}
